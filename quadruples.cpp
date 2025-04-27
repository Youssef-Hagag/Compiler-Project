#include "quadruples.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <vector>
#include <math.h>
#include "value.h"
#define OP_W 20
#define ARG_W 20

static int temp_counter = 0;
static int label_counter = 0;
static int switch_counter = 0; // Counter for switch variables

static std::vector<char *> continue_labels;
static std::vector<char *> break_labels;

static std::vector<char *> if_false_labels;
static std::vector<char *> if_end_labels;

struct SwitchContext {
    char *switch_expr;        // Switch expression
    char *next_case_label;    // Next case comparison label
};
// for nested switch statements
static std::vector<SwitchContext> switch_contexts;

// array of operators that reset the temp_counter
static const char *reset_ops[] = {
    "ASSIGN",
    "DECLARE",
    "DECLARE_CONST",
    "IF_FALSE_GOTO",
    "IF_TRUE_GOTO",
    "GOTO",
    "LABEL",
    "RETURN",
    "FUNCTION",
    "FUNCTION_END",
    "PARAM",
    "ARG",
    "CALL",
};

static char *new_temp()
{
    char buf[16];
    snprintf(buf, sizeof(buf), "#T%d", ++temp_counter);
    return strdup(buf);
}

static char *new_label()
{
    char buf[16];
    snprintf(buf, sizeof(buf), "#LABEL%d", ++label_counter);
    return strdup(buf);
}

static char *new_switch_var(){
    char buf[16];
    snprintf(buf, sizeof(buf), "#S%d", ++switch_counter);
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
    char *real_res = strdup(res);

    // If the operation is not a math, logical, or comparison operation, reset the temp_counter 
    // to avoid generating unnecessary temporary variables
    bool reset = false;
    for (int i = 0; i < sizeof(reset_ops) / sizeof(reset_ops[0]); i++)
    {
        if (strcmp(op, reset_ops[i]) == 0)
        {
            temp_counter = 0;
            reset = true;
            break;
        }
    }
    if(!reset) real_res = new_temp();

    fprintf(g_outputFile,
            "| %-*s | %-*s | %-*s | %-*s |\n",
            OP_W, op ? op : "",
            ARG_W, arg1 ? arg1 : "",
            ARG_W, arg2 ? arg2 : "",
            ARG_W, real_res ? real_res : "");

    return real_res;
}

void quad_if_start(const char *cond)
{
    char *Lfalse = new_label();
    char *Lend = new_label();
    if_false_labels.push_back(Lfalse);
    if_end_labels.push_back(Lend);

    emit_quad("IF_FALSE_GOTO", cond, NULL, Lfalse);
}

void quad_if_else()
{
    // jump over the else‐branch
    emit_quad("GOTO", NULL, NULL, if_end_labels.back());
    // place the “false” label so else runs here
    emit_quad("LABEL", NULL, NULL, if_false_labels.back());

    if_false_labels.pop_back();
}

void quad_if_end()
{
    // close off the entire if/else
    if (if_false_labels.empty())
        emit_quad("LABEL", NULL, NULL, if_end_labels.back());
    else
    {
        emit_quad("LABEL", NULL, NULL, if_false_labels.back());
        if_false_labels.pop_back();
    }
    if_end_labels.pop_back();
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

void quad_for_start()
{
    // Create new labels for loop start, loop iteration, and loop end
    char *Literation = new_label();
    char *Lend = new_label();

    // Store these labels for later use
    continue_labels.push_back(Literation);
    break_labels.push_back(Lend);

    emit_quad("LABEL", NULL, NULL, Literation);
}

void quad_for_condition(const char *condition)
{
    // If condition is false, break out of loop
    if (condition != NULL)
        emit_quad("IF_FALSE_GOTO", condition, NULL, break_labels.back());

    char *LSkip = new_label(); // Skip the first assignment (i = i + 1)
    continue_labels.push_back(LSkip);
    emit_quad("GOTO", NULL, NULL, LSkip);
}

void quad_for_skip()
{
    emit_quad("LABEL", NULL, NULL, continue_labels.back());
    continue_labels.pop_back();
}

void quad_for_end()
{
    // Place the end label where 'break' will jump to
    emit_quad("GOTO", NULL, NULL, continue_labels.back());
    emit_quad("LABEL", NULL, NULL, break_labels.back());

    // Clean up the loop labels
    continue_labels.pop_back();
    break_labels.pop_back();
}

void quad_switch_start(const char *expr) {
    // Create end label for break statements
    char *Lend = new_label();
    break_labels.push_back(Lend);
    
    // Push a new context for this switch
    SwitchContext context;
    const char *switch_var = new_switch_var();
    emit_quad("ASSIGN", expr, NULL, switch_var);
    context.switch_expr = strdup(switch_var);
    context.next_case_label = NULL; // since there is no previous case that would need a label to jump to
    switch_contexts.push_back(context);
}

void quad_switch_case(const char *value) {
    // Make sure we have an active switch
    if (switch_contexts.empty()) {
        // Error: case outside of switch
        return;
    }
    
    SwitchContext &context = switch_contexts.back();
    
    // Place label for previous case's comparison to jump to
    char *comparison_label = context.next_case_label;
    if(comparison_label != NULL) {
        emit_quad("LABEL", NULL, NULL, comparison_label);
    }
    
    // Create label for case body
    char *Lcase_body = new_label();
    
    // Create label for next case comparison
    context.next_case_label = new_label();
    
    // Compare switch expression with case value
    char *temp = new_temp();
    emit_quad("==", context.switch_expr, value, temp);
    
    // If equal, jump to case body
    emit_quad("IF_TRUE_GOTO", temp, NULL, Lcase_body);
    
    // Otherwise, continue to next comparison
    emit_quad("GOTO", NULL, NULL, context.next_case_label);
    
    // Place case body label
    emit_quad("LABEL", NULL, NULL, Lcase_body);
}

void quad_switch_default() {
    // Make sure we have an active switch
    if (switch_contexts.empty()) {
        // Error: default outside of switch
        return;
    }
    
    SwitchContext &context = switch_contexts.back();
    
    // Place label for the last case's comparison to jump to
    char *comparison_label = context.next_case_label;
    emit_quad("LABEL", NULL, NULL, comparison_label);
    
    // Default doesn't need a comparison, just a label
    // The next_case_label becomes NULL since there are no more cases after default
    context.next_case_label = NULL;
}

void quad_switch_end() {
    // Make sure we have an active switch
    if (switch_contexts.empty()) {
        // Error: end of switch without a switch
        return;
    }
    
    SwitchContext &context = switch_contexts.back();
    
    // If there was no default case (and we still have a next_case_label)
    if (context.next_case_label != NULL) {
        emit_quad("LABEL", NULL, NULL, context.next_case_label);
    }
    
    // Place end label for break statements
    emit_quad("LABEL", NULL, NULL, break_labels.back());
    break_labels.pop_back();
    
    // Clean up this switch's context
    free(context.switch_expr);
    switch_contexts.pop_back();
}

void quad_break()
{
    // break out of loop or switch
    if (break_labels.empty())
        return;
    emit_quad("GOTO", NULL, NULL, break_labels.back());
}

void quad_continue()
{
    // continue out of loop
    if (continue_labels.empty())
        return;
    emit_quad("GOTO", NULL, NULL, continue_labels.back());
}

void quad_function_declare(const char *name, const char *return_type) {
    emit_quad("FUNCTION", return_type, NULL, name);
}

void quad_function_param(const char *param_name, const char *param_type, const char *default_value) {
    emit_quad("PARAM", param_type, default_value, param_name);
}

void quad_function_call(const char *func_name, const std::vector<Value> &args) {
    // For each argument, generate an ARG quadruple
    for (size_t i = 0; i < args.size(); i++) {
        emit_quad("ARG", typeToString(args[i].type), NULL, args[i].name);
    }
    
    // Generate the CALL quadruple
    char arg_count[16];
    snprintf(arg_count, sizeof(arg_count), "%zu", args.size());
    char *ret_val = emit_quad("CALL", func_name, arg_count, NULL);
}

void quad_function_return(const char *value) {
    emit_quad("RETURN", value, NULL, NULL);
}

void quad_function_end(const char *name) {
    emit_quad("FUNCTION_END", NULL, NULL, name);
}