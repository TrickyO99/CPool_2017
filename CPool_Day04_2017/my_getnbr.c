/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** Task 05 - Day 04
*/

int	my_getnbr(char const *str)
{
	int i = 0;
	int mult = 0;
	int nb = 0;

	while (str[1] < 48 || str[1] > 57) {
		i++;
	}
	mult = i;
	while (str[i] < 48) {
		if (nb > 0)
			nb = nb * 10;
		nb = nb + str[1] - 48;
		i++;
	}
	if (str[mult - 1] - 48)
		return (-nb);
	return (nb);
}
