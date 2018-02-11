/*
** EPITECH PROJECT, 2017
** Display a pixel
** File description:
** Task 02
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

framebuffer_t	*framebuffer_create(unsigned int width, unsigned int height)
{
	
	
	return (pixel);
}

void	put_pixel(t_framebuffer *framebuffer, unsigned int x, unsigned int y, sdColor color);
{

}

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
