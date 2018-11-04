//
// Created by Antoine on 04/11/2018.
//

#include "bistro.h"

static bigint_t *mod_pos(bigint_t *a, bigint_t *b, char base)
{
	while (bigint_compare(a, b) >= 0) {
		a = bigint_sub(a, b, base);
		if (!a)
			return (NULL);
	}
	return (a);
}

bigint_t *bigint_mod(bigint_t *a, bigint_t *b, char base)
{
	if (bigint_zero(b))
		return (NULL);
	return (bigint_simplify_neg(a, b, base, mod_pos));
}