/*
** EPITECH PROJECT, 2017
** my_strcapitalize
** File description:
** Task09 - Day06
*/

#include<stdio.h>

char	*my_strcapitalize(char *str)
{
	int i = 0;
	int a = 0;

	while (str[i] != '\0') {
		if (str[i] > 96 && str[i] < 123) {
			if (str[a] < 65 || (str[a] > 90 && str[a] < 97) || str[a] > 122 || i == 0)
				str[i] = str[i] - 32;
		}
		a = i;
		i = i + 1;
	}
	return (str);
}

int main(void)
{
	char a[] = "ajI hwiNI ftabo-nI";
	printf("%s", my_strcapitalize(a));		
}
