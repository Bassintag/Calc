//
// Created by Antoine on 04/11/2018.
//

#include "bistro.h"

bigint_t *bigint_simplify_neg(bigint_t *a, bigint_t *b, char base,
	bigint_t *(*func)(bigint_t *, bigint_t *, char))
{
	if (!a || !b)
		return (NULL);
	if (a->neg && b->neg)
		return (func(bigint_invert(a), bigint_invert(b), base));
	if (a->neg)
		return (bigint_invert(func(bigint_invert(a), b, base)));
	if (b->neg)
		return (bigint_invert(func(a, bigint_invert(b), base)));
	return (func(a, b, base));
}