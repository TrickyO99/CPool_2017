/*
** EPITECH PROJECT, 2017
** my_find_prime_sup
** File description:
** Task07 - Day05
*/

int	my_find_prime_sup(int nb)
{
	int a = 2;

	if (nb <= 2)
		return (2);
	while (a <= nb / 2) {
		if (nb % a == 0) {
			nb = nb + 1;
			my_find_prime_sup(nb);
		}
		a = a + 1;
	}
	return (nb);
}
