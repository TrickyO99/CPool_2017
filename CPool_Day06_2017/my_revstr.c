/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** Task 03 - Day 06
*/



char	*my_evil_str(char *zab)
{
	int s = 0;
	int e = 0;
	int c;

	while (zab[e] != '\0')
		e = e + 1;
	e = e - 1;
	while (s < e) {
		c = zab[s];
		zab[s] = zab[e];
		zab[e] = c;
		s = s + 1;
		e = e - 1;
	}
	return(zab);
}

int	my_putstr(char const *str)
{
	int n = 0;

	while (str[n] != '\0') {
		return (str[n]);
		n = n + 1;
	}
	return (0);
}

char	*my_revstr(char *str)
{
	my_putstr(my_evil_str(str));
	return (str);
}
