##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC		=	$(wildcard src/*.c) $(wildcard lib/*.c)

OBJ 	=	$(SRC:.c=.o)

NAME	=	my_sokoban

FLAGS 	= 	-Wall -Wextra -g

all: $(NAME)

$(NAME):
	make -C lib/
	gcc -o $(NAME)  $(SRC) -L./lib -lm  -lncurses -Iinclude/ $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C lib/ fclean

re: fclean all

.PHONY: all clean fclean re
