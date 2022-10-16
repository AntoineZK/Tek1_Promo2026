##
## EPITECH PROJECT, 2022
## n4s_package
## File description:
## Makefile
##

NAME	= ai

CC	= gcc

RM	= rm -f

SRCS	= $(wildcard need4stek/*.c)

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
