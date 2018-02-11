/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** Task 02 - Day 06
*/

void	my_putchar (char);

int	my_strlen(char const *str)
{
	int n = 0;

	while (str[n] != '\0')
		n++;
	if (n < 10)
		return (n + 48);
	else
		return (n);
}

char	*strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0') {
		dest[i] = src[i];
		i = i + 1;
	}
	while (i > n) {
		dest[i] = '\0';
		i = i + 1;
	}
	return (dest);
}
