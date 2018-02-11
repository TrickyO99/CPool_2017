/*
** EPITECH PROJECT, 2017
** Librairie - OCLOO
** File description:
** my_putstr.c - Fonction qui affiche un char * en entier.
*/

#include <unistd.h>

int	my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		write(1, &str[i], 1);
		i = i + 1;
	}
	return (i);
}
