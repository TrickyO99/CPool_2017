/*
** EPITECH PROJECT, 2017
** Librairie - OCLOO
** File description:
** my_getnbr.c - Fonction qui transforme un nombre sous forme de char * en int.
*/

#include <unistd.h>

int	posornot(char const *str)
{
	int i = 0;
	int m = 0;

	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-') {
			m = m + 1;
		}
		i = i + 1;
	}
	return (m);
}

int	my_getnbr(char const *str)
{
	int i = 0;
	long int nb = 0;

	if (str == NULL)
		return (0);
	i = posornot(str);
	while (nb <= 2147483647 && str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10 + (str[i] - 48);
		i = i + 1;
	}
	if (nb > 2147483647)
		return (0);
	if (posornot(str) % 2 != 0)
		return (-nb);
	return (nb);
}
