#include <stdio.h>
#include <memory.h>
#include "bistro.h"

static int parse_operators(expr_t *out, char *str) {
    if (strlen(str) != 7) {
        return (84);
    }
    out->add_op = str[0];
    out->sub_op = str[1];
    out->mul_op = str[2];
    out->div_op = str[3];
    out->mod_op = str[4];
    out->lpr_op = str[5];
    out->rpr_op = str[6];
    return (0);
}

int main() {
    expr_t expr;
    bigint_t out;
    char *err;

    expr.value = "123/5";
    expr.base = "0123456789";
    parse_operators(&expr, "+-*/%()");
    err = calc(&expr, &out);
    if (err) {
        puts(err);
        return (84);
    }
    bigint_print(&expr, &out);
    return (0);
}