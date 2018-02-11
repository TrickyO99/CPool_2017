/*
** EPITECH PROJECT, 2017
** my_show_word_array
** File description:
** task03
*/

void	my_putchar(char);

int	my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i = i + 1;
	}
	return(0);
}

int	my_show_word_array(char *const *tab)
{
	int oune = 0;

	while (tab[oune] != 0) {
		my_putstr(tab[oune]);
		my_putchar('\n');
		oune = oune + 1;
	}
	return (tab);
}
