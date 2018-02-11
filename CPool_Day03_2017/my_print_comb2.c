/*
** EPITECH PROJECT, 2017
** my_print_comb2
** File description:
** my_print_comb2
*/

int	prout(int a, int b, int c, int d)
{
	if(b < d && a <= c) {
		my_putchar(a);
		my_putchar(b);
		my_putchar(' ');
		my_putchar(c);
		my_putchar(d);
		if (a != 57 || b != 56 || c != 57 || d != 57){
			my_putchar(',');
			my_putchar(' ');
		}
	}
	if (a == 57 && b == 56 && c == 57 && d == 57){
		my_putchar('\n');
	}
}

int	my_print_comp2(void)
{
	int a = 48;
	int b = 48;
	int c = 48;
	int d = 49;

	while (a <= 57) {
		while (b <= 57) {
			while (c <= 57) {
				while (d <= 57) {
					prout(a, b, c, d);
					d++;
				}
				c++;
				d = 48;
			}						
			b++;				
			c = 48;
		}
		a++;
		b = 48;
	} 	
}
