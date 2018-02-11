/*
** EPITECH PROJECT, 2017
** mu_str_isupper
** File description:
** TasK13 - Day06
*/

int	my_str_isupper(char const *str)
{
	int i = 0;
	int a = 0;

	while (str[i] != '\0') {
		if (str[i] > 65 && str[i] < 90)
			a = a + 1;
		i = i + 1;
	}
	if (a == i)
		return (1);
	else
		return (0);
}
