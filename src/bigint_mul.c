//
// Created by Antoine on 04/11/2018.
//

#include "bistro.h"

static bigint_t *mul_pos(bigint_t *a, bigint_t *b, char base)
{
	bigint_t *num = bigint_create(a->len + b->len);
	size_t idx;

	for (size_t i_a = 1; i_a <= a->len; i_a += 1) {
		for (size_t i_b = 1; i_b <= b->len; i_b += 1) {
			idx = num->len - (i_a + i_b - 1);
			for (char i = 0; i < b->value[b->len - i_b]; i += 1) {
				num->value[idx] += a->value[a->len - i_a];
				num->value[idx - 1] += num->value[idx] / base;
				num->value[idx] %= base;
			}
		}
	}
	return (num);
}

bigint_t *bigint_mul(bigint_t *a, bigint_t *b, char base)
{
	return (bigint_simplify_neg(a, b, base, mul_pos));
}