##
## EPITECH PROJECT, 2022
## hunter
## File description:
## Makefile
##

SRC		=	$(wildcard src/*.c) \
			$(wildcard lib/*.c)


OBJ 	=	$(SRC:.c=.o)

NAME	=	my_hunter

FLAGS 	= 	-Wall -Wextra -g -lcsfml-graphics -lcsfml-window -lcsfml-system\
			-lcsfml-audio

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
