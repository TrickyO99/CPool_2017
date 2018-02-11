/*
** EPITECH PROJECT, 2017
** Librairie - OCLOO
** File description:
** my_strlen.c - Fonction qui renvoie le nombre de caractère du char * donné.
*/

int	my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i = i + 1;
	}
	return (i);
}
