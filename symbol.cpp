#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void yyerror(const char *format, ...);
extern int line_num;
bool scope_already_entered = false;
bool scope_already_exited = false;

SymbolTable symbol_table = { .count = 0, .current_scope = 0 };
std::map<std::string, FunctionInfo> function_table;

int add_symbol(const char *name, int type, bool is_initialized) {
    if(symbol_table.count >= MAX_SYMBOLS) 
    {
        yyerror("Symbol table overflow: too many symbols defined");
        return -1;
    }

    // Check if an *active* symbol with the same name exists in the current scope.
    for (int i = symbol_table.count - 1; i >= 0; i--) {
        if (!symbol_table.table[i].active)
            continue;  // Ignore symbols that are no longer in scope.
        if(symbol_table.table[i].scope_level < symbol_table.current_scope)
            break;
        if(strcmp(symbol_table.table[i].name, name) == 0) {
            yyerror("Symbol '%s' already defined in this scope", name);
            return -1;
        }
    }
    
    symbol_table.table[symbol_table.count].name = strdup(name);
    symbol_table.table[symbol_table.count].type = static_cast<ValueType>(type);
    symbol_table.table[symbol_table.count].scope_level = symbol_table.current_scope;
    symbol_table.table[symbol_table.count].declared_line = line_num;
    symbol_table.table[symbol_table.count].is_initialized = is_initialized;
    symbol_table.table[symbol_table.count].is_used = false;
    symbol_table.table[symbol_table.count].active = true; 
    
    switch(type) {
        case TYPE_INT:
            symbol_table.table[symbol_table.count].init_value = make_runtime_value(TYPE_INT);
            break;
        case TYPE_FLOAT:
            symbol_table.table[symbol_table.count].init_value = make_runtime_value(TYPE_FLOAT);
            break;
        case TYPE_CHAR:
            symbol_table.table[symbol_table.count].init_value = make_runtime_value(TYPE_CHAR);
            break;
        case TYPE_BOOL:
            symbol_table.table[symbol_table.count].init_value = make_runtime_value(TYPE_BOOL);
            break;
        case TYPE_STRING:
            symbol_table.table[symbol_table.count].init_value = make_runtime_value(TYPE_STRING);
            break;
        case TYPE_VOID:
            symbol_table.table[symbol_table.count].init_value = make_runtime_value(TYPE_VOID);
            break;
        default:
            symbol_table.table[symbol_table.count].init_value = make_runtime_value(TYPE_INT);
            yyerror("Unknown type for symbol '%s'", name);
    }
    return symbol_table.count++;
}

void add_function(int idx, const char* name, int return_type, const std::vector<int>& param_types, const std::vector<bool>& default_params) {
    // Check if function already exists
    if (function_table.find(name) != function_table.end()) {
        return;
    }

    FunctionInfo info;
    info.idx = idx; // the index of the function in the symbol table
    info.return_type = static_cast<ValueType>(return_type);
    info.param_types.clear();
    for(int type : param_types) {
        info.param_types.push_back(static_cast<ValueType>(type));
    }
    info.default_params.clear();
    for(bool def : default_params) {
        info.default_params.push_back(def);
    }
    function_table[name] = info;
}

bool check_function_call(const char* name,  const ListValue& args) {
    auto it = function_table.find(name);
    if(it == function_table.end()) 
    {
        yyerror("Undeclared function '%s' called", name);
        return false;
    }

    // mark the function as used
    int func_index = find_symbol(name);
    if(func_index != -1) {
        symbol_table.table[func_index].is_used = true;
    }
    const FunctionInfo& info = it->second;
    int least_required_params = 0;
    for(size_t i = 0; i < info.param_types.size(); i++) {
        if(!info.default_params[i]) {
            least_required_params++;
        }
        else {
            break; // stop counting at the first default parameter
        }
    }

    if(args.size < least_required_params) {
        yyerror("Function '%s' expects at least %zu parameters but got %zu", 
            name, least_required_params, args.size);
        return false;
    }

    if(args.size > info.param_types.size()) {
        yyerror("Function '%s' expects at most %zu parameters but got %zu", 
            name, info.param_types.size(), args.size);
        return false;
    }
    
    for(size_t i = 0; i < args.size; i++) {
        if(args.values[i].type != info.param_types[i]) {
            yyerror("Parameter %zu of function '%s' expects type %s but got type %s",
                i+1, name, 
                typeToString(info.param_types[i]), 
                typeToString(args.values[i].type));
            return false;
        }
    }
    
    return true;
}

ValueType get_function_return_type(const char* name) {
    auto it = function_table.find(name);
    if(it == function_table.end()) {
        return TYPE_INT; // Default return type
    }
    return it->second.return_type;
}

bool is_function(int idx) {
    for (const auto& entry : function_table) {
        if (entry.second.idx == idx) {
            return true;
        }
    }
    return false;
}

int find_symbol(const char *name) {
    // Search backward for an active symbol with the given name.
    for (int i = symbol_table.count - 1; i >= 0; i--) {
        if(symbol_table.table[i].active && strcmp(symbol_table.table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void enter_block_scope() {
    if (scope_already_entered) {
        scope_already_entered = false;
        scope_already_exited = true;
        return;
    }
    if(symbol_table.current_scope < MAX_SCOPE_DEPTH) {
        symbol_table.current_scope++;
    }
}

// This function is called when entering a scope without a new block (e.g., in a loop or function definition).
void enter_scope() {
    if(symbol_table.current_scope < MAX_SCOPE_DEPTH) {
        symbol_table.current_scope++;
        scope_already_entered = true; // this is so that the next block does not enter a new scope
    }
}

void exit_scope() {
    if (scope_already_exited) {
        scope_already_exited = false;
        return;
    }
    if(symbol_table.current_scope > 0) {
        // For symbols in the current scope, mark them inactive.
        for (int i = symbol_table.count - 1; i >= 0; i--) {
            if(symbol_table.table[i].scope_level == symbol_table.current_scope) {
                symbol_table.table[i].active = false;
            }
        }
        symbol_table.current_scope--;
    }
    scope_already_entered = false; // reset the flag for the next block
}

void print_symbol_table(const char *filename) {
    FILE *f = fopen(filename, "w");
    if(!f) {
        fprintf(stderr, "Error: cannot open file %s for writing symbol table\n", filename);
        return;
    }
    /* Print table header */
    const char* separator = "+----------------------+--------------------------------+-------+------+-------+-------+----------------------+\n";
    fprintf(f, separator);
    fprintf(f, "| %-20s | %-30s | %-5s | %-4s | %-5s | %-5s | %-20s |\n", 
            "Name", "Type", "Scope", "Line", "Init", "Used", "Initial Value");
    fprintf(f, separator);
    for (int i = 0; i < symbol_table.count; i++) {
        Symbol sym = symbol_table.table[i];
        char type_str[256] = "";        
        // Check if the symbol is a function
        if (is_function(i)) {
            std::string func_name(sym.name);
            auto it = function_table.find(func_name);
            if (it != function_table.end()) {
                FunctionInfo info = it->second;
                // Format parameters and return type
                std::string param_str;
                for (size_t j = 0; j < info.param_types.size(); j++) {
                    if (j > 0) param_str += ", ";
                    param_str += typeToString(info.param_types[j]);
                    if (info.default_params[j]) {
                        param_str += "?";
                    }
                }
                // truncate long function signatures
                std::string func_signature = "(" + param_str + ") -> " + typeToString(info.return_type);
                if (func_signature.length() > 28) {
                    func_signature = func_signature.substr(0, 25) + "...";
                }
                // if the signature is less than 30 characters, add spaces to fill it
                while (func_signature.length() < 30) {
                    func_signature += " ";
                }
                strncpy(type_str, func_signature.c_str(), sizeof(type_str) - 1);
                type_str[sizeof(type_str) - 1] = '\0';
            } else {
                strcpy(type_str, "function (unknown)");
            }
        } else {
            // If it's not a function, just get the type as a string
            strcpy(type_str, typeToString(sym.type));
            if(sym.init_value.is_const) {
                // If it's a constant, append " (const)" to the type string
                strncat(type_str, " (const)", sizeof(type_str) - strlen(type_str) - 1);
            }
        }

        char valueStr[256] = "";
        if (is_function(i)) {
            // If it's a function, set the initial value to "function"
            strcpy(valueStr, "Function");
        }
        else{
            if (!sym.init_value.is_evaluated){
                strcpy(valueStr, "Runtime");
            } else{
                switch(sym.type) {
                    case TYPE_INT:
                        snprintf(valueStr, sizeof(valueStr), "%d", sym.init_value.data.ival);
                        break;
                    case TYPE_FLOAT:
                        snprintf(valueStr, sizeof(valueStr), "%f", sym.init_value.data.fval);
                        break;
                    case TYPE_CHAR:
                        snprintf(valueStr, sizeof(valueStr), "%c", sym.init_value.data.cval);
                        break;
                    case TYPE_BOOL:
                        snprintf(valueStr, sizeof(valueStr), "%s", sym.init_value.data.bval ? "true" : "false");
                        break;
                    case TYPE_STRING:
                        // Truncate long strings if needed
                        if (strlen(sym.init_value.data.sval) > 20) {
                            snprintf(valueStr, sizeof(valueStr), "%.17s...", sym.init_value.data.sval);
                        } else {
                            snprintf(valueStr, sizeof(valueStr), "%s", sym.init_value.data.sval);
                        }
                        break;
                    default:
                        strcpy(valueStr, "unknown");
                }
            }
        }

        // Print the row with new columns
        fprintf(f, "| %-20s | %-30s | %-5d | %-4d | %-5s | %-5s | %-20s |\n", 
            sym.name, 
            type_str,
            sym.scope_level,
            sym.declared_line,
            sym.is_initialized ? "Yes" : "No",
            sym.is_used ? "Yes" : "No",
            valueStr);
    }
    fprintf(f, separator);
    fclose(f);
}

void print_unused_symbols(const char *filename) {
    // continue writing to the errors file
    FILE *f = fopen(filename, "a");
    if(!f) {
        fprintf(stderr, "Error: cannot open file %s for writing unused symbols\n", filename);
        return;
    }
    fprintf(f, "\n---------------------Unused Symbols---------------------\n");
    for (int i = 0; i < symbol_table.count; i++) {
        if(!symbol_table.table[i].is_used) {
            fprintf(f, "Symbol '%s' of type '%s' declared at line %d and not used\n", 
                symbol_table.table[i].name, 
                typeToString(symbol_table.table[i].type), 
                symbol_table.table[i].declared_line);
        }
    }
    fclose(f);
}