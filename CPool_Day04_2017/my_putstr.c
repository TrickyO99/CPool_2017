/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** Task 02 - Day 04
*/

int	my_putstr(char const *str)
{
	int n = 0;

	while (str[n] != '\0') {
		my_putchar(str[n]);
		n++;
	}
	return (0);
}
