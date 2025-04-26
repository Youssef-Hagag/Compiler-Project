#include "quadruples.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <vector>
#include <math.h>
#define OP_W 20
#define ARG_W 20

static int temp_counter = 0;
static int label_counter = 0;

static std::vector<char *> continue_labels;
static std::vector<char *> break_labels;

// return a fresh temp name "t1", "t2", …
static char *new_temp()
{
    char buf[16];
    snprintf(buf, sizeof(buf), "t%d", ++temp_counter);
    return strdup(buf);
}

// return a fresh label name "L1", "L2", …
static char *new_label()
{
    char buf[16];
    snprintf(buf, sizeof(buf), "L%d", ++label_counter);
    return strdup(buf);
}

// Output file management
static const char *g_outputFilePath = "./output/quad.txt";
static FILE *g_outputFile = NULL;

void quad_init_file()
{
    FILE *file = fopen(g_outputFilePath, "w");
    if (file == NULL)
    {
        fprintf(stderr, "Failed to create output file '%s'\n", g_outputFilePath);
        exit(EXIT_FAILURE);
    }
    g_outputFile = file;

    print_border();
    fprintf(g_outputFile,
            "| %-*s | %-*s | %-*s | %-*s |\n",
            OP_W, "OP",
            ARG_W, "ARG1",
            ARG_W, "ARG2",
            ARG_W, "RESULT");
    print_border();
}

void print_border(void)
{
    fputc('+', g_outputFile);
    for (int i = 0; i < OP_W + 2; i++)
        fputc('-', g_outputFile);
    fputc('+', g_outputFile);
    for (int i = 0; i < ARG_W + 2; i++)
        fputc('-', g_outputFile);
    fputc('+', g_outputFile);
    for (int i = 0; i < ARG_W + 2; i++)
        fputc('-', g_outputFile);
    fputc('+', g_outputFile);
    for (int i = 0; i < ARG_W + 2; i++)
        fputc('-', g_outputFile);
    fputs("+\n", g_outputFile);
}
void quad_close_table(void)
{
    print_border();
}

char *emit_quad(const char *op, const char *arg1, const char *arg2, const char *res)
{
    char *real_res = res ? strdup(res) : new_temp();

    if (strcmp(op, "ASSIGN") == 0 || strcmp(op, "DECLARE") == 0 || strcmp(op, "DECLARE_CONST") == 0)
    {
        temp_counter = 0; // Reset temp counter for assignment
    }

    fprintf(g_outputFile,
            "| %-*s | %-*s | %-*s | %-*s |\n",
            OP_W, op ? op : "",
            ARG_W, arg1 ? arg1 : "",
            ARG_W, arg2 ? arg2 : "",
            ARG_W, real_res ? real_res : "");

    return real_res;
}

void quad_while_start(const char *condition)
{
    // 1) new begin/end labels
    char *Lbegin = new_label(), *Lend = new_label();
    continue_labels.push_back(Lbegin);
    break_labels.push_back(Lend);
    // 2) mark the loop head
    emit_quad("LABEL", NULL, NULL, Lbegin);
    // 3) if false, break out
    emit_quad("IF_FALSE_GOTO", condition, NULL, Lend);
}

void quad_while_end()
{
    // 4) at end of body, jump back to head
    emit_quad("GOTO", NULL, NULL, continue_labels.back());
    // 5) place loop‐end label
    emit_quad("LABEL", NULL, NULL, break_labels.back());
    // 6) unwind stacks
    continue_labels.pop_back();
    break_labels.pop_back();
}

void quad_do_while_start()
{
    char *Lbody = new_label(), *Lend = new_label();
    continue_labels.push_back(Lbody);
    break_labels.push_back(Lend);

    // label start of body
    emit_quad("LABEL", NULL, NULL, Lbody);
}

void quad_do_while_end(const char *condition)
{
    // after body, evaluate condition → if true, repeat
    emit_quad("IF_TRUE_GOTO", condition, NULL, continue_labels.back());
    // place end label
    emit_quad("LABEL", NULL, NULL, break_labels.back());
    continue_labels.pop_back();
    break_labels.pop_back();
}