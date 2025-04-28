%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "error.h"
#include "value.h"
#include "quadruples.h"
#include <vector>
#include <stdarg.h>

extern int yylex(void);
void yyerror(const char *s, ...);
Value handle_unary_op(const char* op_name, const char* op_code, char* var_name, bool is_prefix);
void handle_assignment(const char* var, Value expr, const char* op, int line_num);
extern int line_num;

// For multiple declarations
int current_decl_type;

// Function handling
char* current_function_name;
int current_function_idx;
int current_return_type = -1;
bool seen_return = false;
std::vector<int> param_types;
std::vector<bool> default_params;
bool seen_default_param = false;

// loop and switch handling
int is_loop = 0;
int is_switch = 0;
%}

%union {
    Value val;
    ListValue list_val;
    char *str;
    char *relop;
    int type_val;
}

/* Token declarations */
%token <val> INTEGER FLOAT_LITERAL CHAR_LITERAL BOOL_LITERAL STRING_LITERAL
%token <str> VARIABLE
%token <type_val> TYPE VOID
%token <relop> RELOP
%token IF ELSE WHILE DO FOR RETURN SWITCH CASE DEFAULT BREAK CONTINUE CONST
%token LAND LOR POW INC DEC BIT_AND BIT_OR BIT_XOR LSHIFT RSHIFT BIT_NOT
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token BIT_AND_ASSIGN BIT_OR_ASSIGN BIT_XOR_ASSIGN LSHIFT_ASSIGN RSHIFT_ASSIGN

/* Non-terminals producing a Value */
%type <val> expression opt_expression assignment opt_assignment expression_or_assignment 
%type <val> parameters parameter_list function_call function
%type <list_val> argument_list_opt non_empty_argument_list

/* Operator precedence - lowest first */
%right '='
%left LOR
%left LAND
%left BIT_OR
%left BIT_XOR
%left BIT_AND
%left RELOP
%left LSHIFT RSHIFT
%left '+' '-'
%left '*' '/' '%'
%right UMINUS '!' BIT_NOT
%right POW

%%

// The program starts with zero or more statements, or function definitions
program:
      /* empty */ { }
    | program statement { }
    | program function { }
    ;

statements:
      /* empty */ {}
    | statements statement {}
    ;

statement:
      declaration
    | expression ';'
    | block // Note: blocks in this language are able to be anywhere even outside functions
    | assignment ';'
    | if_statement 
    | while_statement 
    | do_while_statement
    | for_statement
    | switch_statement
    | RETURN opt_expression ';' { 
          if(current_return_type == -1) {
              yyerror("Return statement not in function");
          } else {
              seen_return = true;
              if(current_return_type == TYPE_VOID && $2.name != NULL) {
                  yyerror("Void function cannot return a value");
              } else if(current_return_type == TYPE_VOID || !type_mismatch(current_return_type, $2.type)) {
                  printf("[Line %d] Return statement\n", line_num);
                  emit_quad("RETURN", $2.name, NULL, NULL);
              }
          }
      }
    | BREAK ';' { if(!is_loop && !is_switch) yyerror("Break statement not in loop or switch"); quad_break(); }
    | CONTINUE ';' { if(!is_loop) yyerror("Continue statement not in loop"); quad_continue(); }
    | error ';' { yyerrok; } // Error recovery: skip to the next semicolon
    ;

declarations:
      /* empty */ {}
    | declarations declaration
    ;

declaration:
      TYPE VARIABLE ';' {
          int idx = add_symbol($2, $1);
          if (idx != -1) {
            printf("[Line %d] Declaration: %s\n", line_num, $2);
            emit_quad("DECLARE", typeToString($1), NULL, $2);
          }
      }
    | TYPE VARIABLE '=' expression_or_assignment ';' {
          /* check type compatibility between declared type and initializer */
          if(!type_mismatch($1, $4.type)) {
            int idx = add_symbol($2, $1, true);
            if(idx != -1) {
                symbol_table.table[idx].init_value = $4;
                symbol_table.table[idx].init_value.is_const = false;
                printf("[Line %d] Declaration with init: %s = ...\n", line_num, $2);
                emit_quad("DECLARE", typeToString($1), $4.name, $2);
            }
          }
      }
    | CONST TYPE VARIABLE '=' expression_or_assignment ';' {
        /* check type compatibility between declared type and initializer */
        if(!type_mismatch($2, $5.type)) {
            int idx = add_symbol($3, $2, true);
            if(idx != -1) {
                symbol_table.table[idx].init_value = $5;
                symbol_table.table[idx].init_value.is_const = true;
                printf("[Line %d] Constant declaration: %s = ...\n", line_num, $3);
                emit_quad("DECLARE_CONST", typeToString($2), $5.name, $3);
            } 
        }
      }
    ;

block:
      '{' { enter_block_scope(); } declarations statements '}' { exit_scope(); }
    ;

assignment:
      VARIABLE '=' expression_or_assignment {
          handle_assignment($1, $3, NULL, line_num);
      }
    | VARIABLE ADD_ASSIGN expression_or_assignment {
          handle_assignment($1, $3, "+", line_num);
      }
    | VARIABLE SUB_ASSIGN expression_or_assignment {
          handle_assignment($1, $3, "-", line_num);
      }
    | VARIABLE MUL_ASSIGN expression_or_assignment {
          handle_assignment($1, $3, "*", line_num);
      }
    | VARIABLE DIV_ASSIGN expression_or_assignment {
          handle_assignment($1, $3, "/", line_num);
      }
    | VARIABLE MOD_ASSIGN expression_or_assignment {
          handle_assignment($1, $3, "%", line_num);
      }
    | VARIABLE BIT_OR_ASSIGN expression_or_assignment {
          handle_assignment($1, $3, "BIT_OR", line_num);
      }
    | VARIABLE BIT_AND_ASSIGN expression_or_assignment {
          handle_assignment($1, $3, "BIT_AND", line_num);
      }
    | VARIABLE BIT_XOR_ASSIGN expression_or_assignment {
          handle_assignment($1, $3, "BIT_XOR", line_num);
      }
    | VARIABLE LSHIFT_ASSIGN expression_or_assignment {
          handle_assignment($1, $3, "LSHIFT", line_num);
      }
    | VARIABLE RSHIFT_ASSIGN expression_or_assignment {
          handle_assignment($1, $3, "RSHIFT", line_num);
      }
;


// Used for x = y = 5
expression_or_assignment:
      expression 
    | assignment
    ;

expression:
      INTEGER
    | FLOAT_LITERAL 
    | CHAR_LITERAL
    | BOOL_LITERAL
    | STRING_LITERAL
    | VARIABLE {
          int idx = find_symbol($1);
          if(idx == -1) {
              yyerror("Undeclared variable '%s' used in expression", $1);
              $$ = make_runtime_value(TYPE_INT);
          } 
          else if(is_function(idx)) {
              yyerror("Function '%s' used as variable", $1);
              $$ = make_runtime_value(symbol_table.table[idx].type);
          }
          else if(symbol_table.table[idx].is_initialized == false) {
              yyerror("Variable '%s' used before initialization", $1);
              $$ = make_runtime_value(symbol_table.table[idx].type);
              $$.name = symbol_table.table[idx].name;
          }
          else{
              symbol_table.table[idx].is_used = true;
              if(symbol_table.table[idx].init_value.is_const && symbol_table.table[idx].init_value.is_evaluated) {
                  $$ = symbol_table.table[idx].init_value;
              } 
              else {
                  $$ = make_runtime_value(symbol_table.table[idx].type);
              }
              $$.name = symbol_table.table[idx].name;
          }
      }
    | expression '+' expression { $$ = add_values($1, $3); $$.name = emit_quad("+", $1.name, $3.name, NULL); }
    | expression '-' expression { $$ = sub_values($1, $3); $$.name = emit_quad("-", $1.name, $3.name, NULL); }
    | expression '*' expression { $$ = mul_values($1, $3); $$.name = emit_quad("*", $1.name, $3.name, NULL); }
    | expression '/' expression { $$ = div_values($1, $3); $$.name = emit_quad("/", $1.name, $3.name, NULL); }
    | expression '%' expression { $$ = mod_values($1, $3); $$.name = emit_quad("%", $1.name, $3.name, NULL); }
    | expression POW expression { $$ = pow_values($1, $3); $$.name = emit_quad("^", $1.name, $3.name, NULL); }
    | '-' expression %prec UMINUS { $$ = neg_value($2); $$.name = emit_quad("MINUS", $2.name, NULL, NULL); }
    | '!' expression { $$ = not_value($2); $$.name = emit_quad("NOT", $2.name, NULL, NULL); }
    | expression LAND expression { $$ = and_values($1, $3); $$.name = emit_quad("AND", $1.name, $3.name, NULL); }
    | expression LOR expression { $$ = or_values($1, $3); $$.name = emit_quad("OR", $1.name, $3.name, NULL); }
    | '(' expression ')' { $$ = $2; }
    | expression RELOP expression { $$ = compare_values($1, $3, $2); $$.name = emit_quad($2, $1.name, $3.name, NULL); }
    | expression LSHIFT expression { $$ = lshift_values($1, $3); $$.name = emit_quad("LSHIFT", $1.name, $3.name, NULL); }
    | expression RSHIFT expression { $$ = rshift_values($1, $3); $$.name = emit_quad("RSHIFT", $1.name, $3.name, NULL); }
    | expression BIT_AND expression { $$ = bit_and_values($1, $3); $$.name = emit_quad("BIT_AND", $1.name, $3.name, NULL); }
    | expression BIT_OR expression { $$ = bit_or_values($1, $3); $$.name = emit_quad("BIT_OR", $1.name, $3.name, NULL); }
    | expression BIT_XOR expression { $$ = bit_xor_values($1, $3); $$.name = emit_quad("BIT_XOR", $1.name, $3.name, NULL); }
    | BIT_NOT expression { $$ = bit_not_value($2); $$.name = emit_quad("BIT_NOT", $2.name, NULL, NULL); }
    | function_call {}
    | INC VARIABLE { $$ = handle_unary_op("increment", "INC", $2, true); }
    | DEC VARIABLE { $$ = handle_unary_op("decrement", "DEC", $2, true); }
    | VARIABLE INC { $$ = handle_unary_op("increment", "INC", $1, false); }
    | VARIABLE DEC { $$ = handle_unary_op("decrement", "DEC", $1, false); }

opt_expression:
      /* empty */ { $$.name = NULL; }
    | expression
    ;

opt_assignment:
      /* empty */ { $$.name = NULL; }
    | assignment
    ;

//--------------------------------------------------------------------------[Flow Control (If/Loops/Switch)]--------------------------------------------------------------------------//
if_statement:
      IF '(' expression ')' { printf("[Line %d] If statement\n", line_num); enter_scope(); quad_if_start($3.name); } if_body { exit_scope(); quad_if_end(); }
    ;

if_body:
      statement
    | statement ELSE { enter_scope(); quad_if_else(); } statement { exit_scope(); }

while_statement:
      WHILE '(' expression ')' { is_loop++; printf("[Line %d] While loop\n", line_num); enter_scope(); quad_while_start($3.name) } statement { is_loop--; exit_scope(); quad_while_end(); }
    ;

do_while_statement:
      DO { is_loop++; printf("[Line %d] Do-While loop\n", line_num); enter_scope(); } statement { is_loop--; exit_scope(); } WHILE '(' expression ')' ';' {}
    ;

for_statement:
      FOR '(' { enter_scope(); } opt_assignment ';' { 
          printf("[Line %d] For loop\n", line_num);
          is_loop++;
          quad_for_start(); 
      } opt_expression { 
          quad_for_condition($7.name);
      } ';' expression_or_assignment
      {
        quad_for_skip();
      }
       ')' statement 
      { 
          exit_scope();
          is_loop--;
          quad_for_end();
      }
    | FOR '(' { enter_scope(); } declaration { 
          printf("[Line %d] For loop\n", line_num);
          is_loop++;
          quad_for_start(); 
      } opt_expression { 
          quad_for_condition($6.name);
      } ';' expression_or_assignment
      {
          quad_for_skip();
      }
       ')' statement 
      { 
          exit_scope();
          is_loop--;
          quad_for_end();
      }
    ;

switch_statement:
      SWITCH '(' expression ')' {  is_switch++; printf("[Line %d] Switch statement\n", line_num); enter_scope();  quad_switch_start($3.name); } switch_body { exit_scope();  quad_switch_end(); }
    ;

switch_body:
      '{' case_list '}' { is_switch--; }
      | '{' case_list DEFAULT { quad_switch_default(); } ':' statements { quad_switch_case_end(); } '}' { is_switch--; }
    ;

case_list:
      /* empty */ {}
    | case_list CASE INTEGER { quad_switch_case($3.name); } ':' statements { quad_switch_case_end(); }
    ;

//--------------------------------------------------------------------------[Functions]--------------------------------------------------------------------------//
function:
      TYPE VARIABLE '(' { 
        int idx = add_symbol($2, $1, true);
        if (idx != -1) {
            printf("[Line %d] Function definition: %s\n", line_num, $2); 
            current_function_name = strdup($2);
            current_return_type = $1;
            current_function_idx = idx;
            param_types.clear();
            default_params.clear();
            seen_default_param = false;
            seen_return = false;
            quad_function_declare($2, typeToString($1));
        }
        enter_scope(); // Noitce that the function name itself is in a scope higher than the parameters and body 
      } parameters ')' block {
          if (current_function_name != NULL) {
              if (current_return_type != TYPE_VOID && !seen_return) {
                  yyerror("Non-void function '%s' does not return a value", current_function_name);
              }
              quad_function_end(current_function_name);
              add_function(current_function_idx, current_function_name, current_return_type, param_types, default_params);
              free(current_function_name);
              current_return_type = -1;
          } 
          exit_scope(); 
      }
    | VOID VARIABLE '(' { 
        int idx = add_symbol($2, $1, true);
        if (idx != -1) {
            printf("[Line %d] Function definition: %s\n", line_num, $2); 
            current_function_name = strdup($2);
            current_return_type = $1;
            current_function_idx = idx;
            param_types.clear();
            default_params.clear();
            seen_default_param = false;
            quad_function_declare($2, typeToString($1));
        }
        enter_scope(); // Notice that the function name itself is in a scope higher than the parameters and body 
      } parameters ')' block {
          if (current_function_name != NULL) {
              quad_function_end(current_function_name);
              add_function(current_function_idx, current_function_name, current_return_type, param_types, default_params);
              free(current_function_name);
              current_return_type = -1;
          } 
          exit_scope(); 
      }
    | error '}' { yyerrok; exit_scope(); } // Error recovery: skip to the next closing brace
    ;

parameters:
      /* empty */ {}
    | parameter_list
    ;

parameter_list:
    parameter {}
    | parameter_list ',' parameter
    ;

parameter:
      TYPE VARIABLE { 
        if (seen_default_param)
            yyerror("Non-default parameter '%s' after a default one", $2);
        
        add_symbol($2, $1, true);
        param_types.push_back($1);
        default_params.push_back(false);
        quad_function_param($2, typeToString($1), NULL);
      }
    | TYPE VARIABLE '=' expression_or_assignment // yes...yes parameters can have "x = y = 5" too in c++
      {
        if(!type_mismatch($1, $4.type)) {
            int idx = add_symbol($2, $1, true);
            if(idx != -1) {
                symbol_table.table[idx].init_value = $4;
                symbol_table.table[idx].init_value.is_const = false;
            }
        }
        param_types.push_back($1);
        default_params.push_back(true);
        seen_default_param = true;
        quad_function_param($2, typeToString($1), $4.name);
      }
    ;

function_call:
      VARIABLE '(' argument_list_opt ')' {
          printf("[Line %d] Function call: %s\n", line_num, $1); 
          if(check_function_call($1, $3)){
            // Convert list of arguments to vector of names
            std::vector<Value> arg_names;
            for (int i = 0; i < $3.size; i++) {
                arg_names.push_back($3.values[i]);
            }
            
            // Add quadruples for function call
            quad_function_call($1, arg_names);
          }
          $$ = make_runtime_value(get_function_return_type($1)); 
      }
    ;

// Optional argument list: either empty or a non-empty list
argument_list_opt:
      /* empty */ { $$ = make_empty_list(); }
    | non_empty_argument_list
    ;

// Non-empty argument list requires at least one expression
non_empty_argument_list:
      expression { $$ = make_list($1); }
    | non_empty_argument_list ',' expression { $$ = append_to_list($1, $3); }
    ;
%%

void yyerror(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    // Calculate required buffer size
    int len = snprintf(NULL, 0, "[Line %d] Error: ", line_num) + 
              vsnprintf(NULL, 0, format, args) + 1;
    
    // Allocate buffer
    char *msg = (char *)malloc(len);
    if (!msg) {
        va_end(args);
        return;
    }
    
    // Format the message
    sprintf(msg, "[Line %d] Error: ", line_num);
    vsprintf(msg + strlen(msg), format, args);
    
    fprintf(stderr, "%s\n", msg);
    free(msg);
    va_end(args);
}

Value handle_unary_op(const char* op_name, const char* op_code, char* var_name, bool is_prefix) {
    Value result;
    int idx = find_symbol(var_name);
    
    if (idx == -1) {
        yyerror("Undeclared variable '%s' used in %s %s", var_name, 
                is_prefix ? "prefix" : "postfix", op_name);
        result = make_runtime_value(TYPE_INT);
    } 
    else if (is_function(idx)) {
        yyerror("Function '%s' used as variable in %s", var_name, op_name);
        result = make_runtime_value(symbol_table.table[idx].type);
    }
    else if (symbol_table.table[idx].type != TYPE_INT && symbol_table.table[idx].type != TYPE_FLOAT) {
        yyerror("Invalid type for %s '%s'", op_name, var_name);
        result = make_runtime_value(symbol_table.table[idx].type);
    }
    else if (symbol_table.table[idx].is_initialized == false) {
        yyerror("Variable '%s' used before initialization in %s", var_name, op_name);
        result = make_runtime_value(symbol_table.table[idx].type);
        result.name = symbol_table.table[idx].name;
    }
    else if (symbol_table.table[idx].init_value.is_const) {
        yyerror("Cannot %s constant '%s'", op_name, var_name);
        result = make_runtime_value(symbol_table.table[idx].type);
    }
    else {
        symbol_table.table[idx].is_used = true;
        result = make_runtime_value(symbol_table.table[idx].type);
        result.name = is_prefix 
            ? quad_prefix(op_code, var_name)
            : quad_postfix(op_code, var_name);
    }
    
    return result;
}

void handle_assignment(const char* var, Value expr, const char* op, int line_num)
{
    printf("[Line %d] Assignment: %s %s ...\n", line_num, var, op ? op : "=");
    
    int idx = find_symbol(var);
    if(idx == -1) {
        yyerror("Undeclared variable '%s' used in assignment", var);
    }
    else if(is_function(idx)) {
        yyerror("Function '%s' used as variable", var);
    }
    else {
        if(symbol_table.table[idx].init_value.is_const) {
            yyerror("Cannot assign to constant '%s'", var);
        }
        else if(!type_mismatch(symbol_table.table[idx].type, expr.type)) {
            if(op == NULL) {
                // Simple assignment '='
                emit_quad("ASSIGN", expr.name, NULL, var);
            }
            else {
                // Compound assignment
                char* tmp = emit_quad(op, var, expr.name, NULL);
                emit_quad("ASSIGN", tmp, NULL, var);
            }
        }
    }
}


int main(int argc, char **argv) {
    const char *input_fname = "input.mel";

    if (argc > 1) {
        input_fname = argv[1];
        // size_t len = strlen(input_fname);
        // if (len < 5 || strcmp(input_fname + len - 4, ".mel") != 0) {
        //     fprintf(stderr, "Error: input file must have a \".mel\" extension (got \"%s\")\n", input_fname);
        //     return 1;
        // }
    }
    
    // Create output directory if it doesn't exist
    if (system("mkdir output") == -1) {
        fprintf(stderr, "Error: cannot create output directory\n");
        return 1;
    }

    if (freopen(input_fname, "r", stdin) == NULL) {
        fprintf(stderr, "Error: cannot open %s for reading\n", input_fname);
        exit(1);
    }
    if (freopen("output/errors.txt", "w", stderr) == NULL) {
        fprintf(stderr, "Error: cannot open output/errors.txt for writing\n");
        exit(1);
    }
    fprintf(stderr, "---------------------ERRORS---------------------\n");
    quad_init_file();
    yyparse();
    quad_close_table();
    fclose(stdin);
    fclose(stderr);
    print_symbol_table("output/symbol_table.txt");
    print_unused_symbols("output/errors.txt");
    
    return 0;
}
