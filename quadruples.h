#ifndef QUADRUPLES_H
#define QUADRUPLES_H

#include <stdio.h>
#include <stdbool.h>

FILE *quad_init_file(char *path);

void quad_set_output(char *p, FILE *f);
void quad_close_table(void);
void print_border(void);

void emit_quad(const char *op, const char *arg1, const char *arg2, const char *res);

void quad_push_integer(int v);
void quad_push_float(float v);
void quad_push_string(const char *s);

void quad_generate_operation(const char *inst);

// e.g. identifier handling
void quad_handle_identifier(const char *name, const char *action);
void quad_handle_identifier_2(const char *dest, const char *action, const char *src);
void quad_handle_identifier_3(const char *dest, const char *action, const char *src);

void quad_register_loop_end(int id);

void quad_create_loop_start(int loopId, char *labelType);

void quad_jump_to_loop_start(char *labelType);

void quad_finalize_loop_start();

void quad_conditional_jump(int labelId);

void quad_finalize_conditional();

void quad_register_switch_var(char *id);

void quad_use_switch_var();

void quad_clear_switch_var();

#endif // QUADRUPLES_H