/*
** EPITECH PROJECT, 2017
** my_strstr
** File description:
** Task 04 - Day 06
*/

char	*my_strstr(char *str, char const *to_find)
{
	int i = 0;
	int a = 0;

	while (str[i] != '\0') {
		while (str[i + a] == to_find[a]) {
			a = a + 1;
			if (to_find[a] == '\0') {
				return (&(str[i]));
			}
		}
		i = i + 1;
		a = 0;
	}
	return (0);
}
