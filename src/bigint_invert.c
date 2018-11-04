//
// Created by Antoine on 04/11/2018.
//

#include "bistro.h"

bigint_t *bigint_invert(bigint_t *num) {
    if (!num)
        return (NULL);
    num->neg = !num->neg;
    return (num);
}