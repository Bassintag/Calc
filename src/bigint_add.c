//
// Created by Antoine on 04/11/2018.
//

#include "bistro.h"

static char needs_more_size(bigint_t *a, bigint_t *b, char base)
{
	return (a->len == b->len && a->value[0] + b->value[0] >= base);
}

static bigint_t *add_pos(bigint_t *a, bigint_t *b, char base)
{
	bigint_t *num = bigint_create(
		MAX(a->len, b->len) + needs_more_size(a, b, base));
	char ret = 0;
	size_t idx;

	if (!num)
		return (NULL);
	for (size_t i = 1; i <= num->len; i += 1) {
		idx = num->len - i;
		num->value[idx] = ret;
		if (i <= a->len)
			num->value[idx] += a->value[a->len - i];
		if (i <= b->len)
			num->value[idx] += b->value[b->len - i];
		ret = num->value[idx] / base;
		num->value[idx] %= base;
	}
	return (num);
}

bigint_t *bigint_add(bigint_t *a, bigint_t *b, char base)
{
	if (!a || !b)
		return (0);
	if (a->neg && b->neg)
		return (bigint_invert(
			bigint_add(bigint_invert(a), bigint_invert(b), base)));
	if (a->neg)
		return (bigint_sub(b, a, base));
	if (b->neg)
		return (bigint_sub(a, b, base));
	return (add_pos(a, b, base));
}