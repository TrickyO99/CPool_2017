/*
** EPITECH PROJECT, 2017
** my_print_params
** File description:
** Task 04 - Day 07
*/

int	main(int argc, char **argv)
{
	int i = 0;

	while (argc > 0) {
		argc = argc - 1;
		my_putstr(argv[i]);
		my_putchar('\n');
		i = i + 1;
	}
	return (0);
}
