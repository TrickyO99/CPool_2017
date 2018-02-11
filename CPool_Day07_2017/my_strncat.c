/*
** EPITECH PROJECT, 2017
** my_strncat
** File description:
** Task 03 - Day 06
*/

char *strncat(char *dest, char const *src, int nb)
{
	int dest_len = strlen(dest);
	int i = 0;
	
	while (i < nb && src[i] != '\0') {
		dest[dest_len + i] = src[i];
		i = i + 1
	}
	dest[dest_len + i] = '\0';	
	return (dest);
}
