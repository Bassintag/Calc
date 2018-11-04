//
// Created by Antoine on 04/11/2018.
//

#include "bistro.h"

const char *tokens_value(const list_t *list)
{
	return ((token_t *) list->value)->value;
}
