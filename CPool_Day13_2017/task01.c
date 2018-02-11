/*
** EPITECH PROJECT, 2017
** OPENING A WINDOW
** File description:
** TASK 01
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

int	main(void)
{
	sfVideoMode mode = {800, 600, 32};
	sfRenderWindow* window;
	sfEvent event;

	window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
	if (!window)
		return (0);
	while (sfRenderWindow_isOpen(window))
	{
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		sfRenderWindow_clear(window, sfBlack);
	}
	sfRenderWindow_display(window);
}
