//
// Created by Antoine on 04/11/2018.
//

#include <stdio.h>
#include "bistro.h"

char *calc(const expr_t *expr, bigint_t *out) {
    list_t *tokens = expr_tokenize(expr);
    bigint_t *ret;

    if (tokens == NULL)
        return ("Expression has invalid syntax");
    ret = tokens_eval(expr, tokens);
    if (ret == NULL)
        return ("Expression has invalid token(s)");
    out->value = ret->value;
    out->len = ret->len;
    out->neg = ret->neg;
    return (0);
}