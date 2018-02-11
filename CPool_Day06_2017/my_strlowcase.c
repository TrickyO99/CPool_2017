/*
** EPITECH PROJECT, 2017
** my_strlowcase
** File description:
** Task08 - Day 06
*/

char	*my_strlowcase(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] > 40 && str[i] < 91)
			str[i] = str[i] + 32;
		i = i + 1;
	}
	return (str);
}
