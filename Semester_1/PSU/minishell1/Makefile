##
## EPITECH PROJECT, 2022
## B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
## File description:
## Makefile
##

SRC		=	$(wildcard src/*.c) \
			$(wildcard lib/*.c)

OBJ 	=	$(SRC:.c=.o)

NAME	=	mysh

FLAGS 	= 	-Wall -Wextra -g

all: $(NAME)

$(NAME):
	make -C lib/
	gcc -o $(NAME) $(SRC) -L./lib -lm -Iinclude/ $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C lib/ fclean

re: fclean all

.PHONY: all clean fclean re
