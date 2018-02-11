/*
** EPITECH PROJECT, 2017
** my_rev_params
** File description:
** Task 05 - Day 06
*/

int	main(int argc, char **argv)
{
	while (argc > 0) {
		argc = argc - 1;
		my_putstr(argv[argc]);
		my_putchar('\n');
	}
	return (0);
}
