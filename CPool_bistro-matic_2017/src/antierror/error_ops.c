/*
** EPITECH PROJECT, 2017
** BTTF - OCLOO
** File description:
** bistro-matic - error_ops.c
*/

#include <unistd.h>

int	same_ops(char const *ops, char now, int avoid)
{
	int o = 0;

	while (ops[o] != '\0') {
		if (now == ops[o] && avoid != o)
			return (84);
		o = o + 1;
	}
	return (0);
}

int	error_ops(char const *ops)
{
	int o = 0;

	while (ops[o] != '\0') {
		if (same_ops(ops, ops[o], o) == 84)
			return (84);
		o = o + 1;
	}
	return (0);
}
