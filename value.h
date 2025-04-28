#ifndef VALUE_H
#define VALUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Type codes for our Value type.
enum ValueType { 
    TYPE_INT = 1, 
    TYPE_FLOAT, 
    TYPE_CHAR, 
    TYPE_BOOL, 
    TYPE_STRING,
    TYPE_VOID,
};

typedef struct {
    char *name;
    ValueType type;
    struct {
        int ival;
        float fval;
        char cval;
        bool bval;
        char* sval;
    } data;
    bool is_const;
    bool is_evaluated; // 1: evaluated at compile time, 0: evaluated at runtime
} Value;

typedef struct {
    Value *values;
    size_t size;
} ListValue;


/* Creation helper functions */
Value make_runtime_value(ValueType t);
Value make_int(int v);
Value make_float(float v);
Value make_char(char v);
Value make_bool(int v);
Value make_string(const char *s);
ListValue make_empty_list();
ListValue make_list(Value first_val);
ListValue append_to_list(ListValue list, Value new_val);

/* Operator helper functions */
bool type_mismatch(int a, int b);
const char* typeToString(int type);
bool evaluatable(Value a, Value b);
Value handle_types(Value a, Value b, const char *op);
char* valueToString(Value v);
Value add_values(Value a, Value b);
Value sub_values(Value a, Value b);
Value mul_values(Value a, Value b);
Value div_values(Value a, Value b);
Value mod_values(Value a, Value b);
Value pow_values(Value a, Value b);
Value neg_value(Value a);
Value and_values(Value a, Value b);
Value or_values(Value a, Value b);
Value not_value(Value a);
Value bit_and_values(Value a, Value b);
Value bit_or_values(Value a, Value b);
Value bit_xor_values(Value a, Value b);
Value bit_not_value(Value a);
Value lshift_values(Value a, Value b);
Value rshift_values(Value a, Value b);
Value compare_values(Value a, Value b, const char *op);

#endif // VALUE_H
