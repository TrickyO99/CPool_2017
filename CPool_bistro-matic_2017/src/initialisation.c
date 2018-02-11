/*
** EPITECH PROJECT, 2017
** BTTF - OCLOO
** File description:
** bistro-matic - initialisation.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	init_operation(post_t **last, char *nbr)
{
	post_t *new_nombre = malloc(sizeof(post_t));

	new_nombre->value = nbr;
	new_nombre->prev = (*last);
	new_nombre->next = NULL;
	(*last)->next = new_nombre;
	*last = new_nombre;
}

post_t	*initialisation(char *nbr, char const *expr, char *pile, int *cursor)
{
	post_t *tmp = malloc(sizeof(post_t));

	tmp->value = nbr;
	tmp->next = NULL;
	tmp->prev = NULL;
	pile[0] = expr[*cursor];
	return (tmp);
}

void	inclusion(post_t **last, char *pile, int *p)
{
	post_t *operand;

	operand = malloc(sizeof(post_t));
	operand->value = malloc(sizeof(char) * 2);
	operand->value[0] = pile[*p];
	operand->value[1] = '\0';
	operand->prev = (*last);
	operand->next = NULL;
	(*last)->next = operand;
	*last = operand;
	*p = *p - 1;
}
