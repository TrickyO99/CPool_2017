e/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** 
*/

int     my_put_nbr(int nb)
{
	int n = abs(nb);
	int e = abs(nb);
	int x = 1000000000;

	if (nb == 0)
		my_putchar(48);
	if (nb < 0)
		my_putchar(45);
	while (x > abs(nb))
		x = x / 10;
	while (x != 1 && x != 0) {
		n = n / x;    
		if (n < 10)
			my_putchar(n + 48);
		e = e % x;
		x = x / 10;
		n = e;
	}
	if (n != 0)
		my_putchar(n + 48);
}
