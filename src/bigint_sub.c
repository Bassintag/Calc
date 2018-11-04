//
// Created by Antoine on 04/11/2018.
//

#include "bistro.h"

static bigint_t *sub_pos(bigint_t *a, bigint_t *b, char base) {
    bigint_t *num = bigint_create(a->len);
    size_t idx;

    if (!num)
        return (NULL);
    for (size_t i = 1; i <= num->len; i += 1) {
        idx = num->len - i;
        num->value[idx] += a->value[a->len - i];
        if (i <= b->len)
            num->value[idx] -= b->value[b->len - i];
        if (num->value[idx] < 0) {
            num->value[idx - 1] -= 1;
            num->value[idx] += base;
        }
    }
    return (num);
}

bigint_t *bigint_sub(bigint_t *a, bigint_t *b, char base) {
    int cmp;

    if (!a || !b)
        return (0);
    if (a->neg && b->neg)
        return (bigint_sub(bigint_invert(b), bigint_invert(a), base));
    if (a->neg)
        return (bigint_invert(bigint_add(bigint_invert(a), b, base)));
    if (b->neg)
        return (bigint_add(a, bigint_invert(b), base));
    cmp = bigint_compare(a, b);
    if (cmp == 0)
        return (bigint_create(1));
    if (cmp < 0)
        return (bigint_invert(sub_pos(b, a, base)));
    return (sub_pos(a, b, base));
}