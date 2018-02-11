/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** Task11 - Day06
*/

int	my_str_isnum(char const *str)
{
	int i = 0;
	int a = 0;

	while (str[i] != '\0') {
		if (str[i] > 47 || str[i] < 58)
			a = a + 1;
		i = i + 1;
	}
	if (a == i)
		return (1);
	else
		return (0);
}
