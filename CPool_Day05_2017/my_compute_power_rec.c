/*
** EPITECH PROJECT, 2017
** my_compute_power_rec
** File description:
** Task 04 - Day 05
*/

int	my_compute_power_rec(int nb, int p)
{
	int a = nb;

	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	if (p > 1)
		a = nb * my_compute_power_rec(nb, p - 1);
	return (a);
}
