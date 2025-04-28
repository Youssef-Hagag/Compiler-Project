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
extern int line_num;

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
%token LAND LOR POW INC DEC

/* Non-terminals producing a Value */
%type <val> expression opt_expression declaration assignment opt_assignment expression_or_assignment statement if_statement while_statement 
%type <val> do_while_statement for_statement switch_statement case_list function
%type <val> parameters parameter_list function_call program block declarations statements
%type <list_val> argument_list_opt non_empty_argument_list

/* Operator precedence - lowest first */
%right '='
%left LOR
%left LAND
%left RELOP
%left '+' '-'
%left '*' '/' '%'
%right UMINUS '!'
%right POW

%%

// The program starts with zero or more statements, or function definitions
program:

      /* empty */ { }
    | program statement { $$ = $2; }
    | program function { $$ = $2; }
    ;

statements:
      /* empty */ {}
    | statements statement { $$ = $2; }
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
      '{' { enter_block_scope(); } declarations statements '}' { exit_scope(); $$ = $4; }
    ;

assignment:
      VARIABLE '=' expression_or_assignment {
          printf("[Line %d] Assignment: %s = ...\n", line_num, $1);
          int idx = find_symbol($1);
          if(idx == -1) {
              yyerror("Undeclared variable '%s' used in assignment", $1);
          } 
          else if(is_function(idx)) {
              yyerror("Function '%s' used as variable", $1);
          }
          else {
              if(symbol_table.table[idx].init_value.is_const) {
                  yyerror("Cannot assign to constant '%s'", $1);
              }
              // check type compatibility during assignment
              if(!type_mismatch(symbol_table.table[idx].type, $3.type)){
                emit_quad("ASSIGN", $3.name, NULL, $1);
              }
          }

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
    | function_call {}
    | INC VARIABLE {
        int idx = find_symbol($2);
        if(idx == -1) {
            yyerror("Undeclared variable '%s' used in prefix increment", $2);
            $$ = make_runtime_value(TYPE_INT);
        } 
        else if(is_function(idx)) {
            yyerror("Function '%s' used as variable in increment", $2);
            $$ = make_runtime_value(symbol_table.table[idx].type);
        }
        else if(symbol_table.table[idx].init_value.is_const) {
            yyerror("Cannot increment constant '%s'", $2);
            $$ = make_runtime_value(symbol_table.table[idx].type);
        }
        else {
            $$ = make_runtime_value(symbol_table.table[idx].type);
            $$.name = quad_prefix("INC", $2);
        }
      }
    | DEC VARIABLE {
          int idx = find_symbol($2);
          if(idx == -1) {
              yyerror("Undeclared variable '%s' used in prefix decrement", $2);
              $$ = make_runtime_value(TYPE_INT);
          } 
          else if(is_function(idx)) {
              yyerror("Function '%s' used as variable in decrement", $2);
              $$ = make_runtime_value(symbol_table.table[idx].type);
          }
          else if(symbol_table.table[idx].init_value.is_const) {
              yyerror("Cannot decrement constant '%s'", $2);
              $$ = make_runtime_value(symbol_table.table[idx].type);
          }
          else {
              $$ = make_runtime_value(symbol_table.table[idx].type);
              $$.name = quad_prefix("DEC", $2);
          }
      }
    | VARIABLE INC {
          int idx = find_symbol($1);
          if(idx == -1) {
              yyerror("Undeclared variable '%s' used in postfix increment", $1);
              $$ = make_runtime_value(TYPE_INT);
          } 
          else if(is_function(idx)) {
              yyerror("Function '%s' used as variable in increment", $1);
              $$ = make_runtime_value(symbol_table.table[idx].type);
          }
          else if(symbol_table.table[idx].init_value.is_const) {
              yyerror("Cannot increment constant '%s'", $1);
              $$ = make_runtime_value(symbol_table.table[idx].type);
          }
          else {
              $$ = make_runtime_value(symbol_table.table[idx].type);
              $$.name = quad_postfix("INC", $1);
          }
      }
    | VARIABLE DEC {
          int idx = find_symbol($1);
          if(idx == -1) {
              yyerror("Undeclared variable '%s' used in postfix decrement", $1);
              $$ = make_runtime_value(TYPE_INT);
          } 
          else if(is_function(idx)) {
              yyerror("Function '%s' used as variable in decrement", $1);
              $$ = make_runtime_value(symbol_table.table[idx].type);
          }
          else if(symbol_table.table[idx].init_value.is_const) {
              yyerror("Cannot decrement constant '%s'", $1);
              $$ = make_runtime_value(symbol_table.table[idx].type);
          }
          else {
              $$ = make_runtime_value(symbol_table.table[idx].type);
              $$.name = quad_postfix("DEC", $1);
          }
      }
    ;

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
      } ';' opt_assignment
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
      } ';' opt_assignment
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
    | error '}' { yyerrok; exit_scope(); printf("skipping function body on line %d\n", line_num); } // Error recovery: skip to the next closing brace
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

int main(int argc, char **argv) {
    const char *input_fname = "input.mel";

    if (argc > 1) {
        input_fname = argv[1];
        size_t len = strlen(input_fname);
        if (len < 5 || strcmp(input_fname + len - 4, ".mel") != 0) {
            fprintf(stderr, "Error: input file must have a \".mel\" extension (got \"%s\")\n", input_fname);
            return 1;
        }
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
