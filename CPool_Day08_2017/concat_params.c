/*
** EPITECH PROJECT, 2017
** concat_params
** File description:
** task02
*/

#include<stdlib.h>

int	my_strlen(char *);

char	*concat_params(int argc, char **argv)
{
	int a = 0;
	int b = 0;
	int len = 0;
	int line = 0;
	char *str;

	while (a != argc) {
		len = len + (my_strlen(argv[a]));
		a = a + 1;
	}
	str = malloc(sizeof(char) * len);
	a = 0;
	while (line != argc) {
		while (argv[line][a] != '\0'){
			str[b] = argv[line][a];
			b = b + 1;
			a = a + 1;
		}
		str[b] = '\n';
		a = 0;
		b = b + 1;
		line = line + 1;
	}
	str[b] = '\0';
	return (str);
}
