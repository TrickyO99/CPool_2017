/*
** EPITECH PROJECT, 2017
** my_compute_square_root
** File description:
** Task 05 - Day 05
*/

int     my_compute_square_root(int nb)
{
	int x = 0;

	if (nb < 1)
		return (0);
	while (x * x != nb) {
		x = x + 1;
		if (x > nb)
			return (0);
	}
	return (x);
}
