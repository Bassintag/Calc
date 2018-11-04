//
// Created by Antoine on 04/11/2018.
//

#include "bistro.h"

static int compare(const char *a, size_t len_a, const char *b, size_t len_b) {
    if (len_a > len_b)
        return (1);
    if (len_b > len_a)
        return (-1);
    for (int i = 0; i < len_a; i += 1) {
        if (a[i] > b[i])
            return (1);
        if (a[i] < b[i])
            return (-1);
    }
    return (0);
}

int bigint_compare(const bigint_t *a, const bigint_t *b) {
    size_t i, j;

    if (a->neg && !b->neg)
        return (-1);
    if (!a->neg && b->neg)
        return (1);
    for (i = 0; i < a->len && a->value[i] == 0; i += 1);
    for (j = 0; j < b->len && b->value[j] == 0; b += 1);
    return (compare(a->value + i, a->len - i, b->value + j, b->len - j));
}