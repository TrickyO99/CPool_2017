/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** Task 06 - Day 06
*/

int	my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	while ((s1[i] == s2[i]) && (s1[i] && s2[i]) && (i < n) {
		i = i + 1;
		if ((s1[i] == '\0' && s2[1] == '\0') || (i == n))
			return (0);
		if (s2[i] > s1[i])
			return (1);
		if (s2[i] < s1[i])
			return (-1);
	}
}
