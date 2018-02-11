##
## EPITECH PROJECT, 2017
## BTTF - OCLOO
## File description:
## bistro-matic - Makefile
##

SRC	=	src/main.c				\
		src/antierror/antierror.c		\
		src/antierror/error_base.c		\
		src/antierror/error_ops.c		\
		src/antierror/error_expr.c		\
		src/eval_expr.c				\
		src/find_nbr.c				\
		src/initialisation.c			\
		lib/my/my_getnbr.c			\
		lib/my/my_getstr.c			\
		lib/my/my_strlen.c			\
		lib/my/my_putstr.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g -Iinclude

NAME	=	calc

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
