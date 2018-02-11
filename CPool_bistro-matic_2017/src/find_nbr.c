/*
** EPITECH PROJECT, 2017
** BTTF - OCLOO
** File description:
** bistro-matic - find_nbr.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	no_ops(char exprc, char const *ops)
{
	int o = 0;

	while (ops[o] != '\0') {
		if (ops[o] == exprc)
			return (o);
		o = o + 1;
	}
	return (-1);
}

int	no_base(char exprc, char const *base)
{
	int b = 0;

	while (base[b] != '\0') {
		if (base[b] == exprc)
			return (b);
		b = b + 1;
	}
	return (-1);
}

char	*find_nbr2(int m, char const *expr, int *cursor)
{
	char *nbr = malloc(sizeof(char) * (m + 1));
	int n = 0;

	while (n < m) {
		nbr[n] = expr[*cursor];
		n = n + 1;
		*cursor = *cursor + 1;
	}
	nbr[n] = '\0';
	return (nbr);
}

char	*find_nbr(char const *expr, char const *base, char const *ops,
	int *cursor)
{
	int lock = 0;
	int m = 0;
	int c = *cursor;

	while ((no_ops(expr[c], ops) == -1 ||
		(lock == 0 && (no_ops(expr[c], ops) == 2 ||
	no_ops(expr[c], ops) == 3))) && expr[c] != '\0') {
		if (no_base(expr[c], base) != -1)
			lock = 1;
		c = c + 1;
		m = m + 1;
	}
	return (find_nbr2(m, expr, cursor));
}
