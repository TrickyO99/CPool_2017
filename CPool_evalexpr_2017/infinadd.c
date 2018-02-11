/*
** EPITECH PROJECT, 2017
** project
** File description:
** infinadd
*/

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_strlen(char const *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0') {
		index = index + 1;
	}
	return (index);
}

int	infinadd(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;
	char	*result = NULL;
	int	curseur1 = my_strlen(s1);
	int	curseur2 = my_strlen(s2);
	int	cr = 0;
	
	result = malloc(sizeof (char) * (curseur1 + 2));
	while (s2[j] != '\0') {
		j++;
	}
	printf("j = %d\n", j);
	while (s1[i] != '\0') {
		i++;
        }
	printf("i = %d\n", i);
	i--;
	j--;
	while (i >= 0 && j >= 0) {	
	       	result = (s1[i] - 48) + (s2[j] - 48);
       		j--;
		i--;
		
	}
}
				
	

int	main(int ac, char **av)
{
	printf("%d", infinadd(av[1], av[2]));
	return (0);
}

