##
## EPITECH PROJECT, 2022
## B-CPE-200-NCY-2-1-dante-thomas.dehennault
## File description:
## Makefile
##

SRC		=	$(wildcard src/*.c)

OBJ 	=	$(SRC:.c=.o)

NAME	=	generator

FLAGS 	= 	-Wall -Wextra -g -Ofast

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
