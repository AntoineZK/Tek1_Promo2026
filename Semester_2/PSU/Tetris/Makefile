##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC		 =	$(wildcard src/*.c)	\

OBJ 	 =	$(SRC:.c=.o)

NAME	 =	tetris

CFLAGS 	 = 	-Wall -Wextra -g
LDFLAGS  =  -lm -lmy -lncurses
CPPFLAGS =  -Iinclude/

all: libmy $(NAME)

libmy:
	make -C lib/

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -L./lib $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C lib/ fclean

re: fclean all

.PHONY: all clean fclean re
