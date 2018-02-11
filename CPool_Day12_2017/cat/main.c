/*
** EPITECH PROJECT, 2017
** Cat
** File description:
** Task 01 - Day 11
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include"../bonus/include/my.h"

int	main(int ac, char **av)
{
	int fd = 0;
	char buffer[15000];
	int size = 1;

	if (ac <= 1) {
		while (1 != 0) {
			size = read(fd, buffer, 14999);
			write(1, buffer, size);
		}
	} else {
		fd =  open(av[size], O_RDWR);
		if (fd == -1) {
			write(2, "Error with open\n", 17);
			return(84);
		}
		while (size != 0) {
			size = read(fd, buffer, 14999);
			if (size != 0)
				write(1, buffer, size);
		}
		close(fd);
		return (0);
	}
}
