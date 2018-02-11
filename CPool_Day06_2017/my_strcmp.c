/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** Task06 - Day 06
*/

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] && s2[i]) {
		i = i + 1;
		if (s1[i] == '\0' && s2[1] == '\0')
			return (0);
		if (s2[i] > s1[i])
			return (1);
		if (s2[i] < s1[i])
			return (-1);
	}
}
