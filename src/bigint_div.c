//
// Created by Antoine on 04/11/2018.
//

#include "bistro.h"

static bigint_t *div_pos(bigint_t *a, bigint_t *b, char base) {
    bigint_t *i = bigint_create(1);
    bigint_t *one = bigint_create(1);

    if (!i || !one)
        return (0);
    one->value[0] = 1;
    while (bigint_compare(a, b) > 0) {
        a = bigint_sub(a, b, base);
        bigint_add(i, one, base);
    }
    return (i);
}

bigint_t *bigint_div(bigint_t *a, bigint_t *b, char base) {
    if (bigint_zero(b))
        return (NULL);
    return (bigint_simplify_neg(a, b, base, div_pos));
}