//
// Created by Antoine on 04/11/2018.
//


#include "bistro.h"

token_type_t tokens_type(const list_t *list)
{
	if (list == NULL)
		return (-1);
	return ((token_t *) list->value)->type;
}
