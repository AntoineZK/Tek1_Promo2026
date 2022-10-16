##
## EPITECH PROJECT, 2022
## my_essential
## File description:
## Makefile
##

all: lib asm corewar

lib:
	@make -C lib/

asm:
	@make -C asm/

corewar:
	@make -C corewar/

clean:
	@make clean -C lib/
	@make clean -C asm/
	@make clean -C corewar/

fclean: clean
	@make fclean -C lib/
	@make fclean -C asm/
	@make fclean -C corewar/
	rm -rf vgcore*

re: fclean all

tests_run:
	@ make tests_run -C asm
	@ make tests_run -C corewar

.PHONY: all asm corewar lib clean fclean re tests_run
