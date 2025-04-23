#ifndef QUADRUPLES_H
#define QUADRUPLES_H

#include <stdio.h>
#include <stdbool.h>

FILE *quad_init_file(char *path);

void quad_set_output(char *p, FILE *f);

void quad_generate_function(char *func, char *a);

void quad_generate_return();

void quad_generate_operation(const char *inst);

void quad_push_integer(int v);

void quad_push_float(float v);

void quad_push_string(char *str);

void quad_handle_identifier(char *s, char *a);

void quad_register_loop_end(int id);

void quad_jump_to_loop_end();

void quad_finalize_loop_end();

void quad_create_loop_start(int loopId, char *labelType);

void quad_jump_to_loop_start(char *labelType);

void quad_finalize_loop_start();

void quad_conditional_jump(int labelId);

void quad_finalize_conditional();

void quad_register_switch_var(char *id);

void quad_use_switch_var();

void quad_clear_switch_var();

#endif // QUADRUPLES_H