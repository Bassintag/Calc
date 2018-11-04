//
// Created by Antoine on 04/11/2018.
//

#include "bistro.h"

int bigint_zero(const bigint_t *num) {
    for (int i = 0; i < num->len; i += 1) {
        if (num->value[i] != 0)
            return (0);
    }
    return (1);
}