##
## EPITECH PROJECT, 2021
## B-CPE-110-NCY-1-1-BSQ-enzo.valentin
## File description:
## Makefile
##

SRC = $(shell find src/ -type f -name '*.c')

OBJ = $(SRC:.c=.o)

NAME = my_rpg

CPPFLAGS = -Iinclude

CFLAGS = -Wall -Wextra -Wno-unused-parameter -g

LDFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

LDFLAGS += -Llib -lmy

all: $(NAME)

$(NAME): $(OBJ)
	tar -xf assets.tar
	make -C lib/my
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf assets
	make -C lib/my fclean

re: fclean all
