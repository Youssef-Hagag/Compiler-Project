#ifndef QUADRUPLES_H
#define QUADRUPLES_H

#include <stdio.h>
#include <stdbool.h>

void quad_init_file();
void quad_close_table(void);
void print_border(void);

char* emit_quad(const char *op, const char *arg1, const char *arg2, const char *res);
void quad_while_start(const char *condition);
void quad_while_end();

#endif // QUADRUPLES_H