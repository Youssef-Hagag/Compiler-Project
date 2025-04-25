%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "error.h"
#include "value.h"
#include <vector>
#include <stdarg.h>

#include "quadruples.h"
#include "quadruples.cpp"
extern FILE *quadFile = nullptr;

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
bool is_loop = false;
bool is_switch = false;
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
%token LAND LOR POW

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
    | RETURN expression ';' { 
          if(current_return_type == -1) {
              yyerror("Return statement not in function");
          } else {
              seen_return = true;
              if(current_return_type == TYPE_VOID) {
                  yyerror("Void function cannot return a value");
              } else if(!type_mismatch(current_return_type, $2.type)) {
                  printf("[Line %d] Return statement\n", line_num);
                  //emit_quad("ret", $2.data.sval, NULL, NULL);
              }
          }
      }
    | BREAK ';' { if(!is_loop && !is_switch) yyerror("Break statement not in loop or switch"); }
    | CONTINUE ';' { if(!is_loop) yyerror("Continue statement not in loop"); }
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
            quad_handle_identifier($2, "STORE");

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


                if ($1 == TYPE_INT) {
                    quad_push_integer($4.data.ival);       //
                }else if ($1 == TYPE_FLOAT) {
                    quad_push_float($4.data.fval);
                }else if ($1 == TYPE_STRING || $1 == TYPE_CHAR) {
                    quad_push_string($4.data.sval);
                }
                quad_handle_identifier($2, "STORE");
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

                quad_handle_identifier($3, "STORE");
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
                if ( $3.type == TYPE_INT) {
                    quad_push_integer($3.data.ival);       //
                }else if ($3.type  == TYPE_FLOAT) {
                    quad_push_float($3.data.fval);
                }else if ($3.type  == TYPE_STRING || $3.type == TYPE_CHAR) {
                    quad_push_string($3.data.sval);
                }
                quad_handle_identifier($1, "ST");
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
              yyerror("Undeclared variable used in expression");
              $$ = make_runtime_value(TYPE_INT);
          } 
          else if(is_function(idx)) {
              yyerror("Function '%s' used as variable", $1);
              $$ = make_runtime_value(symbol_table.table[idx].type);
          }
          else if(symbol_table.table[idx].is_initialized == false) {
              yyerror("Variable '%s' used before initialization", $1);
              $$ = make_runtime_value(symbol_table.table[idx].type);
          }
          else{
              symbol_table.table[idx].is_used = true;
              if(symbol_table.table[idx].init_value.is_const && symbol_table.table[idx].init_value.is_evaluated) {
                  $$ = symbol_table.table[idx].init_value;
              } 
              else {
                  $$ = make_runtime_value(symbol_table.table[idx].type);
              }
          }
      }
    | expression '+' expression { $$ = add_values($1, $3); emit_quad("+", $1, $3, "t1")}
    | expression '-' expression { $$ = sub_values($1, $3); }
    | expression '*' expression { $$ = mul_values($1, $3); }
    | expression '/' expression { $$ = div_values($1, $3); }
    | expression '%' expression { $$ = mod_values($1, $3); }
    | expression POW expression { $$ = pow_values($1, $3); }
    | '-' expression %prec UMINUS { $$ = neg_value($2); }
    | '!' expression { $$ = not_value($2); }
    | expression LAND expression { $$ = and_values($1, $3); }
    | expression LOR expression { $$ = or_values($1, $3); }
    | '(' expression ')' { $$ = $2; }
    | expression RELOP expression { $$ = compare_values($1, $3, $2); }
    | function_call {}
    ;

opt_expression:
      /* empty */ {}
    | expression
    ;

opt_assignment:
      /* empty */ {}
    | assignment
    ;

//--------------------------------------------------------------------------[Flow Control (If/Loops/Switch)]--------------------------------------------------------------------------//
if_statement:
      IF '(' expression ')' { printf("[Line %d] If statement\n", line_num); enter_scope(); } if_body { exit_scope(); }
    ;

if_body:
      statement
    | statement ELSE statement

while_statement:
      WHILE '(' expression ')' { is_loop = true; printf("[Line %d] While loop\n", line_num); enter_scope(); } statement { is_loop = false; exit_scope(); }
    ;

do_while_statement:
      DO { is_loop = true; printf("[Line %d] Do-While loop\n", line_num); enter_scope(); } statement { is_loop = false; exit_scope(); } WHILE '(' expression ')' ';' {}
    ;

for_statement:
      FOR '(' { enter_scope(); } opt_assignment ';' opt_expression ';' opt_assignment ')' 
      {
          printf("[Line %d] For loop\n", line_num);
          is_loop = true;
      }
      statement {
          exit_scope();
          is_loop = false;
      }
    | FOR '(' { enter_scope(); } declaration opt_expression ';' opt_assignment ')'
      {
          printf("[Line %d] For loop\n", line_num);
          is_loop = true;
      }
     statement {
          exit_scope();
          is_loop = false;
      }
    ;

switch_statement:
      SWITCH '(' expression ')' {  is_switch = true; printf("[Line %d] Switch statement\n", line_num); enter_scope(); } switch_body { exit_scope(); }
    ;

switch_body:
      '{' case_list '}' { is_switch = false; }
      | '{' case_list DEFAULT ':' statements '}' { is_switch = false; }
    ;

case_list:
      /* empty */ {}
    | case_list CASE INTEGER ':' statements
    ;

//--------------------------------------------------------------------------[Functions]--------------------------------------------------------------------------//
function:
      TYPE VARIABLE '(' { 
        int idx = add_symbol($2, $1, true);
        if (idx == -1) {
        } else {
            printf("[Line %d] Function definition: %s\n", line_num, $2); 
            current_function_name = strdup($2);
            current_return_type = $1;
            current_function_idx = idx;
            param_types.clear();
            default_params.clear();
            seen_default_param = false;
            seen_return = false;
        }
        enter_scope(); // Noitce that the function name itself is in a scope higher than the parameters and body 
        emit_quad("func", $2, NULL, NULL);

      } parameters ')' block {
          if (current_function_name != NULL) {
              if (current_return_type != TYPE_VOID && !seen_return) {
                  yyerror("Non-void function '%s' does not return a value", current_function_name);
              }
              add_function(current_function_idx, current_function_name, current_return_type, param_types, default_params);
              free(current_function_name);
              current_return_type = -1;
          } 
          exit_scope(); 
        emit_quad("endfunc", $2, NULL, NULL);
      }
    | VOID VARIABLE '(' { 
        int idx = add_symbol($2, $1, true);
        if (idx == -1) {
        } else {
            printf("[Line %d] Function definition: %s\n", line_num, $2); 
            current_function_name = strdup($2);
            current_return_type = $1;
            current_function_idx = idx;
            param_types.clear();
            default_params.clear();
            seen_default_param = false;
        }
        enter_scope(); // Noitce that the function name itself is in a scope higher than the parameters and body 
      } parameters ')' block {
          if (current_function_name != NULL) {
              add_function(current_function_idx, current_function_name, current_return_type, param_types, default_params);
              free(current_function_name);
              current_return_type = -1;
          } 
          exit_scope(); 
      }
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
      }
    ;

function_call:
      VARIABLE '(' argument_list_opt ')' {
          printf("[Line %d] Function call: %s\n", line_num, $1); 
          check_function_call($1, $3);
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

    if (freopen(input_fname, "r", stdin) == NULL) {
        fprintf(stderr, "Error: cannot open %s for reading\n", input_fname);
        exit(1);
    }
    if (freopen("output/errors.txt", "w", stderr) == NULL) {
        fprintf(stderr, "Error: cannot open output/errors.txt for writing\n");
        exit(1);
    }
    fprintf(stderr, "---------------------ERRORS---------------------\n");
    quadFile = quad_init_file("./output/quad.txt");
    quad_set_output("./output/quad.txt", quadFile);
    yyparse();
    quad_close_table();
    fclose(stdin);
    fclose(stderr);
    print_symbol_table("output/symbol_table.txt");
    print_unused_symbols("output/errors.txt");
    
    return 0;
}
