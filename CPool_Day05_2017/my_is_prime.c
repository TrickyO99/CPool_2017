/*
** EPITECH PROJECT, 2017
** my_is_prime
** File description:
** Task06 - Day 05
*/

int	my_is_prime(int nb)
{
	int a = 2;

	if (nb < 2)
		return (0);
	while (a <= (nb / 2)) {
		if ((nb % a) == 0)
			return (0);
		a = a + 1;
	}
	return (1);
}
