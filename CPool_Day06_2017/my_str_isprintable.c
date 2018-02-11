/*
** EPITECH PROJECT, 2017
** my_str_isprintable
** File description:
** Task 14 - Day 06
*/

int	my_str_isprintable(char const *str)
{
	int i = 0;
	int a = 0;

	while (str[i] != '\0') {
		if (str[i] > 32 && str[i] < 127)
			a = a + 1;
		i = i + 1;
	}
	if (a == i)
		return (1);
	else
		return (0);
}
