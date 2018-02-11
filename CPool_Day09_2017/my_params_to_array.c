/*
** EPITECH PROJECT, 2017
** my_params_to_array
** File description:
** Task 03 - Day 09
*/

struct	info_param
{
	int length;
	char *str; 
	char *copy;
	char **word_array;
};

int	view_struct(struct info_param (int ac, char **av))
{
	my_strlen(av->length);
	my_putstr(av->str);
	my_putstr(av->copy);
	my_params_to_array(av->word_array);
	return (0);
}

struct info_param *my_params_to_array(int ac, char **av)
{
	struct info_param *av;

	av = malloc(sizeof(struct info_param));
	if (word == NULL)
		return (NULL);
	av->length = length;
	av->str = my_strdup(str);
	av->copy = my_strdup(copy);
	av->word_array = my_params_to_array(word_array);
	return(av);
}
int main(int ac, char **av)
{
	struct info_param	*word;
	word = new_word(int ac, char **av)
	return (0);
}
