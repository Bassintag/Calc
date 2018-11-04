#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "bistro.h"

static int parse_operators(expr_t *out, char *str)
{
	if (strlen(str) != 7) {
		return (84);
	}
	out->add_op = str[0];
	out->sub_op = str[1];
	out->mul_op = str[2];
	out->div_op = str[3];
	out->mod_op = str[4];
	out->lpr_op = str[5];
	out->rpr_op = str[6];
	return (0);
}

int main(int ac, char *av[])
{
	expr_t expr;
	bigint_t out;
	int len;
	char *err;

	if (ac != 4)
		return (84);
	expr.base = av[1];
	if (parse_operators(&expr, av[2]))
		return (84);
	len = atoi(av[3]);
	if (len <= 0)
		return (84);
	expr.value = malloc(sizeof(char) * len + 1);
	if (read(0, expr.value, (size_t) len) != len)
		return (84);
	expr.value[len] = '\0';
	err = calc(&expr, &out);
	if (err) {
		puts(err);
		return (84);
	}
	bigint_print(&expr, &out);
	return (0);
}