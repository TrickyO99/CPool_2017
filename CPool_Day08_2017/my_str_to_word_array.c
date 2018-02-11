/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** Task 04 - Day 08
*/

#include<stdlib.h>

int	my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i = i + 1;
	}
	return (i);
}

int	my_isnum(char c)
{
	return (c >= 48 && c <= 57);
}

int	my_isupper(char c)
{
 	return (c >= 65 && c <= 90);
}

int	my_islower(char c)
{
	return (c >= 97 && c <= 122);
}

int	my_isalpha(char c)
{
	return (my_islower(c) || my_isupper(c));
}

int     my_isalphanum(char c)
{
 	return (my_isalpha(c) || my_isnum(c));
}

int	compteur_str(char const *str)
{
	int x = 0;
	int n = 0;

	while (str[x] != '\0') {
		if (my_isalphanum(str[x])) {
			x = x + 1;
			n = n + 1;
		}
		x = x + 1;
	}
	n = n + 1;
	return (n);
}

char	**my_str_to_word_array(char const *str)
{
	int i = 0;
	int x = 0;
	int y = 0;
	int m;
	char **dest;
	int n;

	m = compteur_str(str);
	dest = malloc(sizeof(char*) * (m + 1));
	n = my_strlen(str);
	
	while (n > 0) {
		dest[n - 1] = malloc(sizeof(char) * (m + 1));
		n = n - 1;
	}
	while (str[x] != '\0') {
		while (my_isalphanum(str[x])) {
			dest[i][y] = str[x];
			x = x + 1;
			y = y + 1;
		}
		dest [i][y] = '\0';
		i = i + 1;
		y = 0;
		x = x + 1;
	}
	return (dest);
}
