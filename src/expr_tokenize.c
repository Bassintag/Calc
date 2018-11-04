//
// Created by Antoine on 04/11/2018.
//

#include <string.h>
#include "bistro.h"

static int number(const char *src, list_t **out, size_t *len) {
    char *value;
    token_t *token;

    *len = 0;
    while (src[*len] >= '0' && src[*len] <= '9')
        *len += 1;
    if (*len) {
        value = strndup(src, *len);
        if (!value)
            return (84);
        token = token_create(value, TKN_NUM);
        if (!token)
            return (84);
        if (list_append(out, token))
            return (84);
    }
    return (0);
}

static token_type_t operator_type(const expr_t *expr, char c) {
    if (c == expr->add_op)
        return (TKN_ADD);
    if (c == expr->sub_op)
        return (TKN_SUB);
    if (c == expr->mul_op)
        return (TKN_MUL);
    if (c == expr->div_op)
        return (TKN_DIV);
    if (c == expr->mod_op)
        return (TKN_MOD);
    if (c == expr->lpr_op)
        return (TKN_LPR);
    if (c == expr->rpr_op)
        return (TKN_RPR);
    return (-1);
}

static int operator(const expr_t *expr, const char *src, list_t **out, size_t *len) {
    char *value;
    token_t *token;
    token_type_t type = operator_type(expr, *src);

    *len = 0;
    if (type == -1)
        return (0);
    *len = 1;
    value = strndup(src, *len);
    if (!value)
        return (84);
    token = token_create(value, type);
    if (!token)
        return (84);
    if (list_append(out, token))
        return (84);
    return (0);
}

static int next_token(const expr_t *expr, char const **src, list_t **out) {
    size_t len;

    if (**src == ' ' || **src == '\n' || **src == '\t') {
        *src += 1;
        return (0);
    }
    if (number(*src, out, &len))
        return (84);
    else if (len) {
        *src += len;
        return (0);
    }
    if (operator(expr, *src, out, &len))
        return (84);
    else if (len) {
        *src += len;
        return (0);
    }
    return (84);
}

list_t *expr_tokenize(const expr_t *expr) {
    const char *src = expr->value;
    list_t *out = NULL;

    while (*src) {
        if (next_token(expr, &src, &out))
            return (NULL);
    }
    return (out);
}