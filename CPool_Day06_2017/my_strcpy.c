/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** Task 01 - Day 06
*/

char	*my_strcpy(char *dest, char const *src)
{
	int i = 0;

	while (dest[i] != '\0') {
		dest[i] = src[i];
		i = i + 1;
	}
	return (dest);
}
