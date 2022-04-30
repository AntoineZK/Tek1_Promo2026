##
## EPITECH PROJECT, 2022
## B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
## File description:
## Makefile
##

NAME	=	libmy.a

SRC	=	$(wildcard *.c)
OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
