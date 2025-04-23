#include "quadruples.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

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

void quad_set_output(char *p, FILE *f)
{
    g_outputFilePath = p;
    g_outputFile = f;
}

// Function handling
void quad_generate_function(char *func, char *a)
{
    if (strcmp(a, "start") == 0)
    {
        fprintf(g_outputFile, "%s:\n", func);
    }
    else if (strcmp(a, "end") == 0)
    {
        fprintf(g_outputFile, "\t END %s\n", func);
    }
    else if (strcmp(a, "call") == 0)
    {
        fprintf(g_outputFile, "\t CALL %s\n", func);
    }
}

void quad_generate_return()
{
    fprintf(g_outputFile, "\t RET\n");
}

// Operation handling
void quad_generate_operation(const char *inst)
{
    fprintf(g_outputFile, "\t %s\n", inst);
}

// Value pushing
void quad_push_integer(int v)
{
    fprintf(g_outputFile, "\t PUSH %d\n", v);
}

void quad_push_float(float v)
{
    fprintf(g_outputFile, "\t PUSH %f\n", v);
}

void quad_push_string(char *str)
{
    fprintf(g_outputFile, "\t PUSH %s\n", str);
}

// Identifier handling
void quad_handle_identifier(char *s, char *a)
{
    fprintf(g_outputFile, "\t %s %s\n", a, s);
}

// Loop end management
void quad_register_loop_end(int id)
{
    g_loopEndLabels.values[++g_loopEndLabels.currentIndex] = id;
}

void quad_jump_to_loop_end()
{
    fprintf(g_outputFile, "\t JMP EndLoop_%d\n", g_loopEndLabels.values[g_loopEndLabels.currentIndex]);
}

void quad_finalize_loop_end()
{
    if (g_loopEndLabels.currentIndex < 0)
    {
        fprintf(stderr, "Error: Loop end stack underflow\n");
        return;
    }
    int endLoopId = g_loopEndLabels.values[g_loopEndLabels.currentIndex--];
    fprintf(g_outputFile, "EndLoop_%d:\n", endLoopId);
}

// Loop start management
void quad_create_loop_start(int loopId, char *labelType)
{
    g_loopStartLabels.values[++g_loopStartLabels.currentIndex] = loopId;
    fprintf(g_outputFile, "Start%s_%d:\n", labelType, loopId);
}

void quad_jump_to_loop_start(char *labelType)
{
    fprintf(g_outputFile, "\t JMP Start%s_%d\n", labelType, g_loopStartLabels.values[g_loopStartLabels.currentIndex]);
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

// Conditional jump handling
void quad_conditional_jump(int labelId)
{
    fprintf(g_outputFile, "\t JF FalseLabel_%d\n", labelId);
    g_conditionalLabels.values[g_conditionalLabels.currentIndex++] = labelId;
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
    fprintf(g_outputFile, "\t PUSH %s\n", g_switchVariables.values[g_switchVariables.currentIndex]);
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