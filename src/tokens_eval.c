//
// Created by Antoine on 04/11/2018.
//

#include <string.h>
#include "bistro.h"

static bigint_t *expr(const expr_t *e, list_t **tokens, char base);

static bigint_t *factor(const expr_t *e, list_t **tokens, char base)
{
	bigint_t *num;

	if (*tokens == NULL)
		return (NULL);
	if (tokens_type(*tokens) == TKN_LPR) {
		num = expr(e, tokens_advance(tokens), base);
		if (tokens_type(*tokens) != TKN_RPR)
			return (NULL);
		return (num);
	} else if (tokens_type(*tokens) == TKN_SUB)
		return (bigint_invert(
			factor(e, tokens_advance(tokens), base)));
	else if (tokens_type(*tokens) == TKN_ADD)
		return (factor(e, tokens_advance(tokens), base));
	else if (tokens_type(*tokens) == TKN_NUM) {
		num = (bigint_parse(e, (char *) tokens_value(*tokens)));
		tokens_advance(tokens);
		return (num);
	}
	return (NULL);
}

static bigint_t *term(const expr_t *e, list_t **tokens, char base)
{
	bigint_t *num = factor(e, tokens, base);
	bigint_t *num1;
	token_type_t type;

	type = tokens_type(*tokens);
	while (type == TKN_MUL || type == TKN_DIV || type == TKN_MOD) {
		if (!num)
			return (NULL);
		num1 = factor(e, tokens_advance(tokens), base);
		if (!num1)
			return (NULL);
		if (type == TKN_MUL)
			num = bigint_mul(num, num1, base);
		else if (type == TKN_DIV)
			num = bigint_div(num, num1, base);
		else
			num = bigint_mod(num, num1, base);
		type = tokens_type(*tokens);
	}
	return (num);
}

static bigint_t *expr(const expr_t *e, list_t **tokens, char base)
{
	bigint_t *num = term(e, tokens, base);
	bigint_t *num1;
	token_type_t type;

	type = tokens_type(*tokens);
	while (type == TKN_ADD || type == TKN_SUB) {
		if (!num)
			return (NULL);
		num1 = factor(e, tokens_advance(tokens), base);
		if (!num1)
			return (NULL);
		if (type == TKN_ADD)
			num = bigint_add(num, num1, base);
		else
			num = bigint_sub(num, num1, base);
		type = tokens_type(*tokens);
	}
	return (num);
}

bigint_t *tokens_eval(const expr_t *e, list_t *tokens)
{
	return expr(e, &tokens, (char) strlen(e->base));
}