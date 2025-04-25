#include "quadruples.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#define OP_W 8
#define ARG_W 20

typedef struct
{
    int count;
    int currentIndex;
    int values[100];
} LabelTracker;

typedef struct
{
    int currentIndex;
    char *values[100];
} IdentifierTracker;

// Global state trackers
static LabelTracker g_conditionalLabels = {0, -1, {0}};
static LabelTracker g_loopStartLabels = {0, -1, {0}};
static LabelTracker g_loopEndLabels = {0, -1, {0}};
static IdentifierTracker g_switchVariables = {-1, {NULL}};

// Output file management
static char *g_outputFilePath = NULL;
static FILE *g_outputFile = NULL;

FILE *quad_init_file(char *path)
{
    FILE *file = fopen(path, "w");
    if (file == NULL)
    {
        fprintf(stderr, "Failed to create output file '%s'\n", path);
        exit(EXIT_FAILURE);
    }
    return file;
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
void quad_set_output(char *path, FILE *f)
{
    g_outputFile = f;

    print_border();
    fprintf(g_outputFile,
            "| %-*s | %-*s | %-*s | %-*s |\n",
            OP_W, "OP",
            ARG_W, "ARG1",
            ARG_W, "ARG2",
            ARG_W, "RESULT");
    print_border();
}

void emit_quad(const char *op, const char *arg1, const char *arg2, const char *res)
{
    fprintf(g_outputFile,
            "| %-*s | %-*s | %-*s | %-*s |\n",
            OP_W, op ? op : "",
            ARG_W, arg1 ? arg1 : "",
            ARG_W, arg2 ? arg2 : "",
            ARG_W, res ? res : "");
}

// Example: pushing constants becomes a quadruple with op "LD"
void quad_push_integer(int v)
{
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", v);
    emit_quad("LD_INT", buf, NULL, NULL);
}

void quad_push_float(float v)
{
    char buf[32];
    snprintf(buf, sizeof(buf), "%f", v);
    emit_quad("LD_FLT", buf, NULL, NULL);
}

void quad_push_string(const char *s)
{
    emit_quad("LD_STR", s, NULL, NULL);
}

// A plain operation with no explicit operands (stack-based IR)
void quad_generate_operation(const char *inst)
{
    emit_quad(inst, NULL, NULL, NULL);
}

void quad_handle_identifier(const char *name, const char *action)
{
    emit_quad(action, name, NULL, NULL);
}

void quad_handle_identifier_2(const char *dest,
                              const char *action,
                              const char *src)
{
    emit_quad(action, dest, src, NULL);
}

void quad_handle_identifier_3(const char *dest,
                              const char *action,
                              const char *src)
{
    emit_quad(action, dest, src, dest);
}

void quad_conditional_jump(int labelId)
{
    char buf[32];
    snprintf(buf, sizeof(buf), "L%d", labelId);
    emit_quad("JF", NULL, NULL, buf);
}

// unconditional jump
void quad_jump_to_loop_start(const char *label)
{
    emit_quad("JMP", NULL, NULL, label);
}

// label emission:
void quad_emit_label(const char *label)
{
    emit_quad("LABEL", label, NULL, NULL);
}

// Loop start management
void quad_create_loop_start(int loopId, char *labelType)
{
    g_loopStartLabels.values[++g_loopStartLabels.currentIndex] = loopId;
    fprintf(g_outputFile, "Start%s_%d:\n", labelType, loopId);
}

void quad_finalize_loop_start()
{
    if (g_loopStartLabels.currentIndex < 0)
    {
        fprintf(stderr, "Error: Loop start stack underflow\n");
        return;
    }
    g_loopStartLabels.currentIndex--;
}

void quad_finalize_conditional()
{
    if (g_conditionalLabels.currentIndex < 0)
    {
        fprintf(stderr, "Error: Conditional label stack underflow\n");
        return;
    }
    fprintf(g_outputFile, "FalseLabel_%d:\n", g_conditionalLabels.values[--g_conditionalLabels.currentIndex]);
}

// Switch statement management
void quad_register_switch_var(char *id)
{
    g_switchVariables.values[++g_switchVariables.currentIndex] = id;
}

void quad_use_switch_var()
{
    if (g_switchVariables.currentIndex < 0)
    {
        fprintf(stderr, "Error: No switch variable defined\n");
        return;
    }
    fprintf(g_outputFile, "\t LD %s\n", g_switchVariables.values[g_switchVariables.currentIndex]);
}

void quad_clear_switch_var()
{
    if (g_switchVariables.currentIndex < 0)
    {
        fprintf(stderr, "Error: Switch variable stack underflow\n");
        return;
    }
    g_switchVariables.currentIndex--;
}