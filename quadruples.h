#ifndef QUADRUPLES_H
#define QUADRUPLES_H

#include <stdio.h>
#include <stdbool.h>

void quad_init_file();
void quad_close_table(void);
void print_border(void);

char* emit_quad(const char *op, const char *arg1, const char *arg2, const char *res);
void quad_if_start(const char *cond);
void quad_if_else();
void quad_if_end();
void quad_while_start(const char *condition);
void quad_while_end();
void quad_do_while_start();
void quad_do_while_end(const char *condition);
void quad_for_start();
void quad_for_condition(const char *condition);
void quad_for_skip();
void quad_for_end();
void quad_switch_start(const char *expr);
void quad_switch_case(const char *value);
void quad_switch_default();
void quad_switch_end();
void quad_break();
void quad_continue();

#endif // QUADRUPLES_H