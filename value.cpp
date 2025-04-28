#include "value.h"
#include <math.h>

extern void yyerror(const char *format, ...);

/* Creation functions */
Value make_runtime_value(ValueType t)
{
    Value val;
    switch (t)
    {
    case TYPE_INT:
        val = make_int(0);
        break;
    case TYPE_FLOAT:
        val = make_float(0.0f);
        break;
    case TYPE_CHAR:
        val = make_char('\0');
        break;
    case TYPE_BOOL:
        val = make_bool(0);
        break;
    case TYPE_STRING:
        val = make_string("");
        break;
    case TYPE_VOID:
        val.type = TYPE_VOID;
        val.data.sval = NULL;
        break;
    default:
        yyerror("Unknown type for runtime value %d", t);
        exit(EXIT_FAILURE);
    }
    val.is_const = false;
    val.is_evaluated = false;
    return val;
}

Value make_int(int v)
{
    Value val;
    val.type = TYPE_INT;
    val.data.ival = v;
    val.data.fval = (float)v; // Store the float representation as well for implicit conversion
    val.is_const = true;
    val.is_evaluated = true;
    val.name = valueToString(val);
    return val;
}

Value make_float(float v)
{
    Value val;
    val.type = TYPE_FLOAT;
    val.data.fval = v;
    val.data.ival = (int)v; // Store the int representation as well for implicit conversion
    val.is_const = true;
    val.is_evaluated = true;
    val.name = valueToString(val);
    return val;
}

Value make_char(char v)
{
    Value val;
    val.type = TYPE_CHAR;
    val.data.cval = v;
    val.data.ival = (int)v; // Store the int representation as well for implicit conversion
    val.is_const = true;
    val.is_evaluated = true;
    val.name = valueToString(val);
    return val;
}

Value make_bool(int v)
{
    Value val;
    val.type = TYPE_BOOL;
    val.data.bval = v;
    val.is_const = true;
    val.is_evaluated = true;
    val.name = valueToString(val);
    return val;
}

Value make_string(const char *s)
{
    Value val;
    val.type = TYPE_STRING;
    // Make a copy of the string so that memory management is centralized.
    val.data.sval = strdup(s);
    val.is_const = true;
    val.is_evaluated = true;
    val.name = valueToString(val);
    return val;
}

ListValue make_empty_list()
{
    ListValue list;
    list.size = 0;
    list.values = NULL;
    return list;
}

ListValue make_list(Value first_val)
{
    ListValue list;
    list.size = 1;
    list.values = (Value *)malloc(sizeof(Value));
    list.values[0] = first_val;
    return list;
}

ListValue append_to_list(ListValue list, Value new_val)
{
    list.size++;
    list.values = (Value *)realloc(list.values, list.size * sizeof(Value));
    list.values[list.size - 1] = new_val;
    return list;
}

char *valueToString(Value v)
{
    char *buffer = (char *)malloc(64); // Allocate a buffer for the string representation
    switch (v.type)
    {
    case TYPE_INT:
        sprintf(buffer, "%d", v.data.ival);
        break;
    case TYPE_FLOAT:
        sprintf(buffer, "%f", v.data.fval);
        break;
    case TYPE_CHAR:
        sprintf(buffer, "%c", v.data.cval);
        break;
    case TYPE_BOOL:
        sprintf(buffer, "%s", v.data.bval ? "true" : "false");
        break;
    case TYPE_STRING:
        sprintf(buffer, "%s", v.data.sval);
        break;
    case TYPE_VOID:
        sprintf(buffer, "void");
        break;
    default:
        strcpy(buffer, "unknown");
    }
    return buffer;
}

const char *typeToString(int type)
{
    switch (type)
    {
    case TYPE_INT:
        return "int";
    case TYPE_FLOAT:
        return "float";
    case TYPE_CHAR:
        return "char";
    case TYPE_BOOL:
        return "bool";
    case TYPE_STRING:
        return "string";
    case TYPE_VOID:
        return "void";
    default:
        return "unknown";
    }
}

// Function to check for type mismatch in assignment
bool type_mismatch(int a, int b)
{
    if (a != b)
    {
        // Check for implicit conversions (int <-> float)
        if (a == TYPE_INT && b == TYPE_FLOAT || a == TYPE_FLOAT && b == TYPE_INT)
        {
            return false;
        }
        else
        {
            yyerror("Type mismatch: cannot assign %s to %s", typeToString(b), typeToString(a));
            return true;
        }
    }
    return false; // no type mismatch
}

bool evaluatable(Value a, Value b)
{
    return a.is_const && b.is_const && a.is_evaluated && b.is_evaluated;
}

// Function to handle type checking for non-constant operators
Value handle_types(Value a, Value b, const char *op)
{
    if (strcmp(op, "+") == 0)
    {
        if (a.type == TYPE_STRING && b.type == TYPE_STRING)
        {
            return make_runtime_value(TYPE_STRING);
        }
        else if (a.type != b.type)
        {
            if (a.type == TYPE_INT && b.type == TYPE_FLOAT)
                return make_runtime_value(TYPE_FLOAT);
            else if (a.type == TYPE_FLOAT && b.type == TYPE_INT)
                return make_runtime_value(TYPE_FLOAT);
            else
            {
                yyerror("Incompatible types for operation '%s'", op);
                return make_runtime_value(TYPE_INT);
            }
        }
        else
        {
            return make_runtime_value(a.type);
        }
    }
    else if (strcmp(op, "-") == 0 || strcmp(op, "*") == 0 ||
             strcmp(op, "/") == 0 || strcmp(op, "**") == 0)
    {
        if (a.type == TYPE_STRING || b.type == TYPE_STRING)
        {
            yyerror("Invalid operation '%s' on string type", op);
            return make_runtime_value(TYPE_INT);
        }
        else if (a.type != b.type)
        {
            if (a.type == TYPE_INT && b.type == TYPE_FLOAT)
                return make_runtime_value(TYPE_FLOAT);
            else if (a.type == TYPE_FLOAT && b.type == TYPE_INT)
                return make_runtime_value(TYPE_FLOAT);
            else
            {
                yyerror("Incompatible types for operation '%s'", op);
                return make_runtime_value(TYPE_INT);
            }
        }
        else
        {
            return make_runtime_value(a.type);
        }
    }
    else if (strcmp(op, "%") == 0)
    {
        if (!(a.type == TYPE_INT && b.type == TYPE_INT))
        {
            yyerror("Invalid operation '%s' on non-integer type", op);
        }
        return make_runtime_value(TYPE_INT);
    }
    else if (strcmp(op, "&&") == 0 || strcmp(op, "||") == 0 || strcmp(op, "!") == 0)
    {
        if (a.type != TYPE_BOOL && a.type != TYPE_INT && a.type != TYPE_FLOAT)
        {
            yyerror("Invalid operation '%s' on non-boolean type", op);
            return make_runtime_value(TYPE_BOOL);
        }
        else if (b.type != TYPE_BOOL && b.type != TYPE_INT && b.type != TYPE_FLOAT)
        {
            yyerror("Invalid operation '%s' on non-boolean type", op);
            return make_runtime_value(TYPE_BOOL);
        }
        else
        {
            return make_runtime_value(TYPE_BOOL);
        }
    }
    else if (strcmp(op, "==") == 0 || strcmp(op, "!=") == 0 ||
             strcmp(op, "<") == 0 || strcmp(op, ">") == 0 ||
             strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0)
    {
        if (type_mismatch(a.type, b.type))
        {
            yyerror("Incompatible types for comparison '%s'", op);
            return make_runtime_value(TYPE_BOOL);
        }
        else
        {
            return make_runtime_value(TYPE_BOOL);
        }
    }
    else if (strcmp(op, "&") == 0 || strcmp(op, "|") == 0 ||
             strcmp(op, "^") == 0 || strcmp(op, "<<") == 0 || strcmp(op, ">>") == 0)
    {
        if (a.type != TYPE_INT || b.type != TYPE_INT)
        {
            yyerror("Bitwise operation '%s' requires integer operands", op);
        }
        return make_runtime_value(TYPE_INT);
    }
    else if (strcmp(op, "~") == 0)
    {
        if (a.type != TYPE_INT)
        {
            yyerror("Bitwise NOT '~' requires integer operand");
        }
        return make_runtime_value(TYPE_INT);
    }
    else
    {
        yyerror("Unknown operator '%s'", op);
        return make_runtime_value(TYPE_INT);
    }
}

/* Operator functions -  Only evaluated if both are constants.
   If any is not a constant, we call handle_types() which returns a runtime value. */

/* + : if both are strings, concatenate; if any is float, use float arithmetic; else use int arithmetic. */
Value add_values(Value a, Value b)
{
    if (!evaluatable(a, b))
        return handle_types(a, b, "+");

    if (a.type == TYPE_STRING && b.type == TYPE_STRING)
    {
        char *str_a = (a.type == TYPE_STRING) ? a.data.sval : valueToString(a);
        char *str_b = (b.type == TYPE_STRING) ? b.data.sval : valueToString(b);

        size_t len = strlen(str_a) + strlen(str_b) + 1;
        char *res = (char *)malloc(len);
        strcpy(res, str_a);
        strcat(res, str_b);

        if (a.type != TYPE_STRING)
            free(str_a);
        if (b.type != TYPE_STRING)
            free(str_b);

        return make_string(res);
    }

    if (a.type == TYPE_FLOAT || b.type == TYPE_FLOAT)
    {
        float fa = (a.type == TYPE_FLOAT) ? a.data.fval : (a.type == TYPE_INT ? a.data.ival : 0);
        float fb = (b.type == TYPE_FLOAT) ? b.data.fval : (b.type == TYPE_INT ? b.data.ival : 0);
        return make_float(fa + fb);
    }

    if (a.type == TYPE_INT && b.type == TYPE_INT)
    {
        return make_int(a.data.ival + b.data.ival);
    }

    yyerror("Incompatible types for addition");
    return make_int(0);
}

/* - operator: only numeric subtraction is supported. */
Value sub_values(Value a, Value b)
{
    if (!evaluatable(a, b))
        return handle_types(a, b, "-");

    if (a.type == TYPE_FLOAT || b.type == TYPE_FLOAT)
    {
        float fa = (a.type == TYPE_FLOAT) ? a.data.fval : (a.type == TYPE_INT ? a.data.ival : 0);
        float fb = (b.type == TYPE_FLOAT) ? b.data.fval : (b.type == TYPE_INT ? b.data.ival : 0);
        return make_float(fa - fb);
    }
    if (a.type == TYPE_INT && b.type == TYPE_INT)
    {
        return make_int(a.data.ival - b.data.ival);
    }
    yyerror("Incompatible types for subtraction");
    return make_int(0);
}

/* * operator */
Value mul_values(Value a, Value b)
{
    if (!evaluatable(a, b))
        return handle_types(a, b, "*");

    if (a.type == TYPE_FLOAT || b.type == TYPE_FLOAT)
    {
        float fa = (a.type == TYPE_FLOAT) ? a.data.fval : (a.type == TYPE_INT ? a.data.ival : 0);
        float fb = (b.type == TYPE_FLOAT) ? b.data.fval : (b.type == TYPE_INT ? b.data.ival : 0);
        return make_float(fa * fb);
    }
    if (a.type == TYPE_INT && b.type == TYPE_INT)
    {
        return make_int(a.data.ival * b.data.ival);
    }
    yyerror("Incompatible types for multiplication");
    return make_int(0);
}

/* / operator */
Value div_values(Value a, Value b)
{
    if (!evaluatable(a, b))
        return handle_types(a, b, "*");

    if ((b.type == TYPE_INT && b.data.ival == 0) || (b.type == TYPE_FLOAT && b.data.fval == 0))
    {
        yyerror("Division by zero");
        return make_int(0);
    }
    if (a.type == TYPE_FLOAT || b.type == TYPE_FLOAT)
    {
        float fa = (a.type == TYPE_FLOAT) ? a.data.fval : (a.type == TYPE_INT ? a.data.ival : 0);
        float fb = (b.type == TYPE_FLOAT) ? b.data.fval : (b.type == TYPE_INT ? b.data.ival : 0);
        return make_float(fa / fb);
    }
    if (a.type == TYPE_INT && b.type == TYPE_INT)
    {
        return make_int(a.data.ival / b.data.ival);
    }
    yyerror("Incompatible types for division");
    return make_int(0);
}

/* % operator */
Value mod_values(Value a, Value b)
{
    if (!evaluatable(a, b))
        return handle_types(a, b, "%");

    if (b.type == TYPE_INT && b.data.ival == 0)
    {
        yyerror("Division by zero");
        return make_int(0);
    }
    if (a.type == TYPE_INT && b.type == TYPE_INT)
    {
        return make_int(a.data.ival % b.data.ival);
    }
    yyerror("Incompatible types for modulo");
    return make_int(0);
}

/* ** operator */
Value pow_values(Value a, Value b)
{
    if (!evaluatable(a, b))
        return handle_types(a, b, "**");

    if (a.type == TYPE_FLOAT || b.type == TYPE_FLOAT)
    {
        float fa = (a.type == TYPE_FLOAT) ? a.data.fval : (a.type == TYPE_INT ? a.data.ival : 0);
        float fb = (b.type == TYPE_FLOAT) ? b.data.fval : (b.type == TYPE_INT ? b.data.ival : 0);
        return make_float(pow(fa, fb));
    }
    if (a.type == TYPE_INT && b.type == TYPE_INT)
    {
        return make_int(pow(a.data.ival, b.data.ival));
    }
    yyerror("Incompatible types for power");
    return make_int(0);
}

/* Unary negation operator */
Value neg_value(Value a)
{
    if (!evaluatable(a, a))
        return handle_types(a, a, "-");

    if (a.type == TYPE_FLOAT)
    {
        return make_float(-a.data.fval);
    }
    else if (a.type == TYPE_INT)
    {
        return make_int(-a.data.ival);
    }
    else if (a.type == TYPE_CHAR)
    {
        return make_char(-a.data.cval);
    }
    else
    {
        yyerror("Invalid type for unary negation");
        return make_int(0);
    }
}

/* Logical AND: treat numeric types as booleans (nonzero is true) */
Value and_values(Value a, Value b)
{
    if (!evaluatable(a, b))
        return handle_types(a, b, "&&");

    int ba = (a.type == TYPE_BOOL) ? a.data.bval : (a.type == TYPE_INT ? a.data.ival : (a.type == TYPE_FLOAT ? (a.data.fval != 0) : 0));
    int bb = (b.type == TYPE_BOOL) ? b.data.bval : (b.type == TYPE_INT ? b.data.ival : (b.type == TYPE_FLOAT ? (b.data.fval != 0) : 0));
    return make_bool(ba && bb);
}

/* Logical OR */
Value or_values(Value a, Value b)
{
    if (!evaluatable(a, b))
        return handle_types(a, b, "||");

    int ba = (a.type == TYPE_BOOL) ? a.data.bval : (a.type == TYPE_INT ? a.data.ival : (a.type == TYPE_FLOAT ? (a.data.fval != 0) : 0));
    int bb = (b.type == TYPE_BOOL) ? b.data.bval : (b.type == TYPE_INT ? b.data.ival : (b.type == TYPE_FLOAT ? (b.data.fval != 0) : 0));
    return make_bool(ba || bb);
}

/* Logical NOT */
Value not_value(Value a)
{
    if (!evaluatable(a, a))
        return handle_types(a, a, "!");

    int ba = (a.type == TYPE_BOOL) ? a.data.bval : (a.type == TYPE_INT ? a.data.ival : (a.type == TYPE_FLOAT ? (a.data.fval != 0) : 0));
    return make_bool(!ba);
}

Value bit_not_value(Value a) {
    if (!evaluatable(a, a))
        return handle_types(a, a, "~"); // dummy second value

    if(a.type == TYPE_INT) {
        return make_int(~a.data.ival);
    }
    yyerror("Invalid operand to ~");
    return make_int(0);
}

Value bit_xor_values(Value a, Value b) {
    if (!evaluatable(a, b))
        return handle_types(a, b, "^");

    if(a.type == TYPE_INT && b.type == TYPE_INT) {
        return make_int(a.data.ival ^ b.data.ival);
    }
    yyerror("Invalid operands to ^");
    return make_int(0);
}

Value bit_or_values(Value a, Value b) {
    if (!evaluatable(a, b))
        return handle_types(a, b, "|");

    if(a.type == TYPE_INT && b.type == TYPE_INT) {
        return make_int(a.data.ival | b.data.ival);
    }
    yyerror("Invalid operands to |");
    return make_int(0);
}

Value bit_and_values(Value a, Value b) {
    if (!evaluatable(a, b))
        return handle_types(a, b, "&");

    if(a.type == TYPE_INT && b.type == TYPE_INT) {
        return make_int(a.data.ival & b.data.ival);
    }
    yyerror("Invalid operands to &");
    return make_int(0);
}

Value rshift_values(Value a, Value b) {
    if (!evaluatable(a, b))
        return handle_types(a, b, ">>");

    if(a.type == TYPE_INT && b.type == TYPE_INT) {
        return make_int(a.data.ival >> b.data.ival);
    }
    yyerror("Invalid operands to >>");
    return make_int(0);
}

Value lshift_values(Value a, Value b) {
    if (!evaluatable(a, b))
        return handle_types(a, b, "<<");

    if(a.type == TYPE_INT && b.type == TYPE_INT) {
        return make_int(a.data.ival << b.data.ival);
    }
    yyerror("Invalid operands to <<");
    return make_int(0);
}

/* Relational comparison operator.
   For strings, only equality and inequality are supported.
   For numeric types, we convert to float if needed.
   Returns a bool Value.
*/
Value compare_values(Value a, Value b, const char *op)
{
    if (!evaluatable(a, b))
        return handle_types(a, b, op);

    Value result = make_bool(0);
    if (a.type == TYPE_STRING && b.type == TYPE_STRING)
    {
        int cmp = strcmp(a.data.sval, b.data.sval);
        if (strcmp(op, "==") == 0)
            result.data.bval = (cmp == 0);
        else if (strcmp(op, "!=") == 0)
            result.data.bval = (cmp != 0);
        else
            yyerror("Relational operator '%s' not supported for strings", op);
        return result;
    }
    float fa, fb;
    if (a.type == TYPE_FLOAT || b.type == TYPE_FLOAT)
    {
        fa = (a.type == TYPE_FLOAT) ? a.data.fval : (a.type == TYPE_INT ? a.data.ival : 0);
        fb = (b.type == TYPE_FLOAT) ? b.data.fval : (b.type == TYPE_INT ? b.data.ival : 0);
    }
    else if (a.type == TYPE_INT && b.type == TYPE_INT)
    {
        fa = a.data.ival;
        fb = b.data.ival;
    }
    else
    {
        yyerror("Incompatible types for comparison");
        return result;
    }
    if (strcmp(op, "<") == 0)
        result.data.bval = (fa < fb);
    else if (strcmp(op, ">") == 0)
        result.data.bval = (fa > fb);
    else if (strcmp(op, "<=") == 0)
        result.data.bval = (fa <= fb);
    else if (strcmp(op, ">=") == 0)
        result.data.bval = (fa >= fb);
    else if (strcmp(op, "==") == 0)
        result.data.bval = (fa == fb);
    else if (strcmp(op, "!=") == 0)
        result.data.bval = (fa != fb);
    else
        yyerror("Unknown relational operator '%s'", op);
    return result;
}
