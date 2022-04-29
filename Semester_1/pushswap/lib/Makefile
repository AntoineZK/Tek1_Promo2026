##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## csfml is the best thing ever
##

NAME	=	libmy.a

SRC	=	$(wildcard *.c)
OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
