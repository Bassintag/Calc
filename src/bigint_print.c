//
// Created by Antoine on 04/11/2018.
//

#include <stdio.h>
#include "bistro.h"

void bigint_print(const expr_t *expr, const bigint_t *num)
{
	int i = 0;

	if (bigint_zero(num)) {
		putchar(expr->base[0]);
		return;
	}
	if (num->neg)
		putchar('-');
	for (; i < num->len - 1 && num->value[i] == 0; i += 1);
	for (; i < num->len; i += 1) {
		putchar(expr->base[num->value[i]]);
	}
}