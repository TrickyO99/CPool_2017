/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** Task 01 - Day 08
*/

#include<stdlib.h>

int	my_strlen(char const *str)
{
	int n = 0;

	while (str[n] != '\0')
		n++;
	return (n);
}

char	*my_strdup(char const *src)
{
	char *point;
	int i = 0;
	int len = my_strlen(src);

	point = malloc(sizeof(char) * (len + 1));
	while (src[i] != '\0') {
		point[i] = src[i];
		i = i + 1;
	}
	return(point);
}
