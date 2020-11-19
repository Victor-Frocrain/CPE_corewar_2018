##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

all:
	make -C asm/
	make -C corewar/

clean:
	make -C asm/ clean
	make -C corewar/ clean

fclean:		clean
	make -C asm/ fclean
	make -C corewar/ fclean

re:		fclean all

tests_run:
	make -C asm/ tests_run
	make -C corewar/ tests_run
	gcovr --exclude test
