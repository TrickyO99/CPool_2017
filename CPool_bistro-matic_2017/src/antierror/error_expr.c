/*
** EPITECH PROJECT, 2017
** BTTF - OCLOO
** File description:
** bistro-matic - error_expr.c
*/

#include <unistd.h>

int	par(char now, char const *ops, int *sp, int *ep)
{
	if (now == ops[0])
		*sp = *sp + 1;
	else if (now == ops[1]) {
		*ep = *ep + 1;
		if (*ep == 1 && *sp == 0)
			return (84);
	}
	return (0);
}

int	expr_in_base_ops(char now, char const *base, char const *ops)
{
	int b = 0;
	int o = 0;

	while (base[b] != '\0') {
		if (now == base[b])
			return (0);
		b = b + 1;
	}
	while (ops[o] != '\0') {
		if (now == ops[o])
			return (0);
		o = o + 1;
	}
	return (84);
}

int	error_expr(char const *expr, char const *base, char const *ops)
{
	int e = 0;
	int sp = 0;
	int ep = 0;

	while (expr[e] != '\0') {
		if ((expr[e] <= 32 && expr[e] >= 127) ||
			expr_in_base_ops(expr[e], base, ops) == 84)
			return (84);
		if (par(expr[e], ops, &sp, &ep) == 84)
			return (84);
		e = e + 1;
	}
	if (sp != ep)
		return (84);
	return (0);
}
