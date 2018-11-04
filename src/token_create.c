//
// Created by Antoine on 04/11/2018.
//

#include <stdlib.h>
#include "bistro.h"

token_t *token_create(const char *value, token_type_t type)
{
	token_t *ret = malloc(sizeof(token_t));

	if (!ret)
		return (NULL);
	ret->value = value;
	ret->type = type;
	return (ret);
}