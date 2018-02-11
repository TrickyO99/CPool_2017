/*
** EPITECH PROJECT, 2017
** my_compute_power_it
** File description:
** Task 03 - Day 05
*/

int	my_compute_power_it(int nb, int p)
{
	int a = nb;
	int b = 0;

	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	while (b != p) {
		a = nb * a;
		b = b + 1;
	}
	return (b);
}
