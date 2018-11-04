//
// Created by Antoine on 04/11/2018.
//

#include <memory.h>
#include "bistro.h"

bigint_t *bigint_parse(const expr_t *e, char *num)
{
	bigint_t *ret = malloc(sizeof(bigint_t));
	size_t len;
	char index;
	int i = 0;

	if (!ret)
		return (NULL);
	len = strlen(num);
	ret->value = malloc(sizeof(char) * (len + 1));
	if (!ret->value)
		return (NULL);
	ret->len = len;
	while (num[i]) {
		index = (char) (strchr(e->base, num[i]) - e->base);
		if (index < 0)
			return (NULL);
		ret->value[i] = index;
		i += 1;
	}
	ret->neg = 0;
	return (ret);
}
