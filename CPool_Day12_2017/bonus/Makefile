##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Task 01 - Day 10
##

#include"../lib/my/"
#include"../include/my.h"

NAME	=	cat

SRC	=	../cat/main.c

OBJ	=	$(SRC:.c=.o)


all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re :	fclean all
