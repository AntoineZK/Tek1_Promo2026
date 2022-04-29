##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	src/ls_flags.c \
		src/ls_l_utils.c \
		src/ls_l.c	\
		src/ls_main.c \
		src/ls_noflags.c	\
		src/my_put_nbr.c \
		src/my_putchar.c\
		src/my_putstr.c \
		src/my_strcat.c \
		src/my_strlen.c


OBJ     =       $(SRC:.c=.o)

NAME	=	my_ls

all:	$(NAME)

$(NAME):
	gcc -g -o $(NAME) $(SRC) -Wextra -Wall -Werror -I include -lm -g

all:	$(NAME)

clean:
		rm -f $(OBJ)
		rm -f *~
		rm -f lib/*.o
		rm -f lib/*~
		rm -f lib/*.a

fclean: clean
		rm -f $(NAME)

re:		fclean all