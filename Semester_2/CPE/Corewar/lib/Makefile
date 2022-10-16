##
## EPITECH PROJECT, 2022
## my_essential
## File description:
## Makefile
##

NAME	=	libmy.a

SRC	=	$(wildcard *.c)\
		$(wildcard printf/*.c)

CFLAGS	=	-I../include/ -Wall -Wextra -Wpedantic -g

OBJ_DIR	=	.obj/
OBJ = $(addprefix ${OBJ_DIR}, $(SRC:.c=.o))

${OBJ_DIR}%.o : %.c
	@mkdir -p ${@D}
	$(CC) -c ${CFLAGS} $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
