/*
** EPITECH PROJECT, 2017
** Task 02 - Day 07
** File description:
** my_strcat
*/

char	*my_strcat(char *dest, char const *src)
{
	int dest_len = my_strlen(dest);
	int i = 0;

	while (src[i] != '\0') {
		dest[dest_len + i] = src[i];
		i = i + 1;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
