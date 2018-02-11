/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** Task 03 - Day 04
*/

int	my_strlen(char const *str)
{
	int n = 0;

	while (str[n] != '\0')
		n++;
	if (n < 10)
		return (n + 48);
	else
		return (n);
}
