/*
** EPITECH PROJECT, 2017
** my_print_digits
** File description:
** my_print_digits
*/

int	my_print_digits(int n)
{
	n = 48;
	while (n < 58) {
		my_putchar(n);
		n = n + 1;
	}
	my_putchar('\n');
}
