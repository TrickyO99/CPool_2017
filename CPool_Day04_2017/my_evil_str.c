/*
** EPITECH PROJECT, 2017
** my_evil_str
** File description:
** Task04 - Day04
*/

char	*my_evil_str(char *str)
{
	int s = 0;
	int e = 0;
	int c;

	while (str[e] != '\0')
		e++;
	e--;
	while (s < e) {
		c = str[s];
		str[s] = str[e];
		str[e] = c;
		s++;
		e--;
	}
	return (str);
}
