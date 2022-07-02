##
## EPITECH PROJECT, 2022
## my_essential
## File description:
## Makefile
##

SRC = $(shell find src/ -type f -name '*.c')

OBJ = $(SRC:.c=.o)

NAME = my_ls

CPPFLAGS = -Iinclude

CFLAGS = -Wall -Wextra -Wno-unused-parameter -Wno-unused-function \
		 -Wno-unused-variable -g

LDFLAGS = -lm -Llib -lmy

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C lib/ fclean

re: fclean all

.PHONY: all clean fclean re
