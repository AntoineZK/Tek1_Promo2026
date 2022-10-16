##
## EPITECH PROJECT, 2022
## my_essential
## File description:
## Makefile
##

NAME	=	corewar

CC	=	gcc

SRCS	=	$(wildcard src/*.c)						\
			$(wildcard src/execute_function/*.c)	\

SRCS_TEST	=	tests/tests_vm.c\

CFLAGS	=	-Wall -Wextra -Wundef -g

LIB_DIR	=	../lib/
LIB	=	my

LIB_TEST	=	criterion

LDFLAGS	=	-L ${LIB_DIR} -l ${LIB}

OBJ_DIR	=	.obj/
OBJ	=	$(addprefix ${OBJ_DIR}, $(SRCS:.c=.o))

exclude	=	${OBJ}/src/main.o
OBJ_TEST	=	$(addprefix ${OBJ_DIR}, $(SRCS_TEST:.c=.o))
OBJ_TEST	+=	$(filter-out ${exclude}, $(OBJ))
${OBJ_DIR}%.o : %.c
	mkdir -p ${@D}
	$(CC) -c ${CFLAGS} $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	${CC} -o ${NAME} ${OBJ} $(LDFLAGS)

tests_run: ${OBJ_TEST}
	${CC} -o ${NAME}_test ${OBJ_TEST} ${LDFLAGS}

clean:
	rm -rf ${OBJ_DIR}
	rm -rf vgcore*

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all asm clean fclean re
