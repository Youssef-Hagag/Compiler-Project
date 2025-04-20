// symbol.h
#ifndef SYMBOL_H
#define SYMBOL_H

#include "value.h"
#include <vector>
#include <map>
#include <string>

#define MAX_SYMBOLS 1000
#define MAX_SCOPE_DEPTH 20

typedef struct {
    char *name;
    ValueType type;
    int scope_level;
    int declared_line;
    bool is_initialized;
    bool is_used;      
    Value init_value;
    bool active;      // true if the symbol is currently in scope
} Symbol;

typedef struct {
    Symbol table[MAX_SYMBOLS];
    int count;
    int current_scope;
} SymbolTable;

extern SymbolTable symbol_table;

int add_symbol(const char *name, int type, bool is_initialized = false);
int find_symbol(const char *name);
void enter_block_scope(); 
void enter_scope();
void exit_scope();
void print_symbol_table(const char *filename);
void print_unused_symbols(const char *filename);

// Function handling
struct FunctionInfo {
    int idx; // the index of the function in the symbol table
    ValueType return_type;
    std::vector<ValueType> param_types;
    std::vector<bool> default_params; // true if the parameter has a default value
};
void add_function(int idx, const char* name, int return_type, const std::vector<int>& param_types, const std::vector<bool>& default_params);
bool check_function_call(const char* name, const ListValue& args);
ValueType get_function_return_type(const char* name);
bool is_function(int idx);
#endif