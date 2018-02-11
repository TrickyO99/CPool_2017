/*
** EPITECH PROJECT, 2017
** BTTF - OCLOO
** File description:
** bistro-matic - eval_expr.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bistro-matic.h"

void	by_zero(int nbr)
{
	if (nbr == 0) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (84);
	}
}

void	calcul(post_t *nombre, char const *ops, int *result)
{
	int i = 0;

	while (nombre->value[0] != ops[i] && ops[i] != '\0')
		i = i + 1;
	switch (i) {
	case 2:	*result = *result + my_getnbr(nombre->prev->value);
		break;
	case 3:	*result = *result - my_getnbr(nombre->prev->value);
		break;
	case 4:	*result = *result * my_getnbr(nombre->prev->value);
		break;
	case 5:	by_zero(my_getnbr(nombre->prev->value));
		*result = *result / my_getnbr(nombre->prev->value);
		break;
	case 6:	by_zero(my_getnbr(nombre->prev->value));
		*result = *result % my_getnbr(nombre->prev->value);
		break;
	}
}

int	parser_calc(post_t *nombre, char const *ops)
{
	int result = my_getnbr(nombre->value);

	nombre = nombre->next;
	while (nombre != NULL) {
		if (nombre->value[1] == '\0') {
			calcul(nombre, ops, &result);
		}
		nombre = nombre->next;
	}
	return (result);
}

char	*eval_expr(char const *base, char const *ops, char const *expr,
	int size)
{
	int cursor = 0;
	int p = 1;
	char *pile = malloc(sizeof(char) * size);
	post_t *nombre = initialisation(find_nbr(expr, base, ops, &cursor),
	expr, pile, &cursor);
	post_t *first = nombre;

	while (expr[cursor] != '\0') {
		pile[p] = expr[cursor];
		cursor = cursor + 1;
		init_operation(&nombre, find_nbr(expr, base, ops, &cursor));
		inclusion(&nombre, pile, &p);
	}
	nombre = first;
	return (my_getstr(parser_calc(nombre, ops)));
}
