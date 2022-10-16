##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Build my libs
##

SRC	= $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = libmy.a

CPPFLAGS = -I../../include

CFLAGS = -Wall -Wextra -g -Wno-parentheses -Wno-unused-result

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all
