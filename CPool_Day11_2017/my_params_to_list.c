/*
** EPITECH PROJECT, 2017
** my_params_to_list
** File description:
** Task 01 - Day 11
*/

#include"include/mylist.h"
#include<stdlib.h>

int	my_put_in_list(struct linked_list **list, char *av)
{
	struct linked_list *element;

	element = malloc(sizeof(*element));
	element->data = av;
	element->next = *list;
	*list = element;
	return (0);
}

linked_list_t	*my_params_to_list(int ac, char * const *av)
{
	struct linked_test *list = NULL;
	int i = 0;

	while (i != ac) {
		my_put_in_list(&list, av[i]);
		i = i + 1;
	}
	return (list);
}
