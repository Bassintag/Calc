//
// Created by Antoine on 04/11/2018.
//

#ifndef BISTRO_BISTRO_H
#define BISTRO_BISTRO_H

#include <stdlib.h>
#include "lists.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct bigint_s {
    char *value;
    size_t len;
    char neg;
} bigint_t;

typedef struct expr_s {
    char *value;
    char *base;
    char add_op;
    char sub_op;
    char mul_op;
    char div_op;
    char mod_op;
    char lpr_op;
    char rpr_op;
} expr_t;

typedef enum token_type_e {
    TKN_NUM,
    TKN_ADD,
    TKN_SUB,
    TKN_MUL,
    TKN_DIV,
    TKN_MOD,
    TKN_LPR,
    TKN_RPR,
} token_type_t;

typedef struct token_s {
    const char *value;
    token_type_t type;
} token_t;

char *calc(const expr_t *expr, bigint_t *out);

token_t *token_create(const char *value, token_type_t type);
list_t **tokens_advance(list_t **tokens);

list_t *expr_tokenize(const expr_t *expr);

token_type_t tokens_type(const list_t *list);
const char *tokens_value(const list_t *list);
bigint_t *tokens_eval(const expr_t *expr, list_t *tokens);

void bigint_print(const expr_t *expr, const bigint_t *num);
int bigint_compare(const bigint_t *a, const bigint_t *b);
int bigint_zero(const bigint_t *num);
bigint_t *bigint_create(size_t len);
bigint_t *bigint_invert(bigint_t *num);
bigint_t *bigint_parse(const expr_t *e, char *num);
bigint_t *bigint_add(bigint_t *a, bigint_t *b, char base);
bigint_t *bigint_sub(bigint_t *a, bigint_t *b, char base);
bigint_t *bigint_mul(bigint_t *a, bigint_t *b, char base);
bigint_t *bigint_div(bigint_t *a, bigint_t *b, char base);
bigint_t *bigint_mod(bigint_t *a, bigint_t *b, char base);
bigint_t *bigint_simplify_neg(bigint_t *a, bigint_t *b, char base, bigint_t *(*)(bigint_t *, bigint_t *, char));

#endif //BISTRO_BISTRO_H
