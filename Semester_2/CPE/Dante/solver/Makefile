##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC		=	$(wildcard src/*.c)

OBJ 	=	$(SRC:.c=.o)

NAME	=	solver

CFLAGS 	= 	-Wall -Wextra -g
LDFLAGS = -O2 -lm -lmy

all: libmy $(NAME)

libmy:
	make -C lib/

$(NAME):
	gcc -o $(NAME) $(SRC) -L./lib -Iinclude/ $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C lib/ fclean

re: fclean all

.PHONY: all clean fclean re
