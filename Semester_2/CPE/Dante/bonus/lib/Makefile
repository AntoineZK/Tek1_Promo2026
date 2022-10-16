##
## EPITECH PROJECT, 2022
## my_essential
## File description:
## Makefile
##

NAME	=	libmy.a

SRC	=	$(wildcard *.c) \
		$(wildcard printf/*.c)
OBJ	=	$(SRC:.c=.o)
CPPFLAGS = -I../include/

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
