//
// Created by Antoine on 04/11/2018.
//

#include <memory.h>
#include "bistro.h"

bigint_t *bigint_create(size_t len)
{
	bigint_t *ret = malloc(sizeof(bigint_t));

	if (!ret)
		return (NULL);
	ret->value = malloc(sizeof(char) * len);
	if (!ret->value)
		return (NULL);
	ret->len = len;
	memset(ret->value, 0, len);
	ret->neg = 0;
	return (ret);
}