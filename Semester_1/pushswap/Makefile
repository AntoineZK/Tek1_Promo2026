##
## EPITECH PROJECT, 2021
## B-CPE-110-NCY-1-1-pushswap-antoine.khalidy
## File description:
## Makefile
##

SRC		=	$(wildcard src/*.c) \
			$(wildcard lib/*.c)


OBJ 	=	$(SRC:.c=.o)

NAME	=	push_swap

FLAGS 	= 	-Wall -Wextra -g

all: $(NAME)

$(NAME):
	make -C lib/
	gcc -O2 -o $(NAME) $(SRC) -L./lib -lm -Iinclude/ $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C lib/ fclean

re: fclean all
