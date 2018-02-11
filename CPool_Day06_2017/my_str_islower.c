/*
** EPITECH PROJECT, 2017
** my_str_islower
** File description:
** Task 11 - Day 06
*/

int	my_str_islower(char const *str)
{
	int i = 0;
	int a = 0;

	while (str[i] != '\0') {
		if (str[i] > 96 || str[i] < 123)
			a = a + 1;
		i = i + 1;
	}
	if (a == i)
		return (1);
	else
		return (0);
}
