/*
** EPITECH PROJECT, 2017
** Librairie - OCLOO
** File description:
** my_put_nbr.c - Fonction qui affiche un nombre
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*my_getstr2(int m, int cop_nb, int t)
{
	int c = 0;
	int n = 0;
	char *nbr = malloc(sizeof(char) * (m + 2));

	if (cop_nb < 0) {
		nbr[0] = '-';
		n = n + 1;
		cop_nb = cop_nb * -1;
	}
	while (t > 0) {
		c = cop_nb / t;
		cop_nb = cop_nb - c * t;
		t = t / 10;
		nbr[n] = c + 48;
		n = n + 1;
	}
	nbr[n] = '\0';
	return (nbr);
}

char	*my_getstr(int nb)
{
	int m = 0;
	int t = 1;
	int cop_nb = nb;

	if (nb < 0)
		m = m + 1;
	while (nb >= 10 || nb <= -10) {
		m = m + 1;
		nb = nb / 10;
		t = t * 10;
	}
	return (my_getstr2(m, cop_nb, t));
}
