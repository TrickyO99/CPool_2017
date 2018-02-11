/*
** EPITECH PROJECT, 2017
** my_compute_factorial_rec
** File description:
** Task 02 - Day 05
*/

int	my_compute_factorial_rec(int nb)
{
	int a = nb;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	if (nb > 1)
		a = a * my_compute_factorial_rec(a - 1);
	return (a);
}
