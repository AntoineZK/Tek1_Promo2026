##
## EPITECH PROJECT, 2022
## my_essential
## File description:
## Makefile
##

NAME	=	libmy.a

SRC	=	$(wildcard lib/*.c) \
		$(wildcard lib/printf/*.c) \
		$(wildcard lib/free/*.c)

OBJ	=	$(SRC:.c=.o)

CPPFLAGS = -I/include/ -Wall -Wextra -Wpedantic

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
