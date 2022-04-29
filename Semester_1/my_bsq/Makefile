##
## EPITECH PROJECT, 2022
## my_essential
## File description:
## Makefile
##

SRC		 =	$(wildcard src/*.c)

OBJ 	 =	$(SRC:.c=.o)

NAME	 =	bsq

CFLAGS 	 = 	-Wall -Wextra -Wundef -g
LDFLAGS  =  -lm -lmy
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
