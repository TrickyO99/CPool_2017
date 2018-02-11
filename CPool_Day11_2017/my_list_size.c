/*
** EPITECH PROJECT, 2017
** my_list_size
** File description:
** Task 02 - Day 11
*/

#include"include/mylist.h"
#include<stdlib.h>

int	my_list_size(linked_list_t const *begin)
{
        int n = 0;

	while (begin != NULL) {
		begin = begin->next;
		n = n + 1;
	}
	return (n);
}
