##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC		=	$(wildcard src/*.c)

OBJ 	=	$(SRC:.c=.o)

NAME	=	my_defender

CFLAGS 	= 	-Wall -Wextra -g

all: libmy $(NAME)

libmy:
	make -C lib/

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lm -L lib -lcsfml-graphics -lcsfml-system -lcsfml-audio -lmy $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C lib/ fclean

re: fclean all

.PHONY: all clean fclean re