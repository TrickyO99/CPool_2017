/*
** EPITECH PROJECT, 2017
** my_print_comb
** File description:
** my_print_comb
*/

void	prout(int x)
{
	if (n1 < n2 && n2 < n3) {
		if (x != 1) {
			my_putchar(',');
			my_putchar(' ');
		}
		x = x + 1;
		my_putchar(n1);
		my_putchar(n2);
		my_putchar(n3);
	}
	n3++;
}

int	my_print_comb(void)
{
	char n1 = 48;
	char n2 = 49;
	char n3 = 50;
	int x = 1;

	while (n1 <= 55) {
		while (n2 <= 56) {
			while (n3 <= 57)
				prout(x);
			n3 = '0';
			n2++;
		}
		n2 = '0';
		n1++;
	}
	my_putchar('\n');
	return (0);
}
