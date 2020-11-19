##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	sources/disasm/error.c			\
			sources/my_getstr.c			\
			sources/disasm/parser.c			\
			sources/disasm/create_asm_file.c	\
			sources/disasm/disasm.c			\
			sources/disasm/fill_asm.c		\
			sources/fill_instruct.c			\
			sources/disasm/is_index.c		\
			sources/reverse_nb.c			\
			sources/op.c				\

SRC_MAIN	=	sources/main.c		\

OBJ		=	$(SRC:%.c=%.o) $(SRC_MAIN:%.c=%.o) $(SRC_MNEMONIC:%.c=%.o)

LIB		=	../../lib/

NAME		=	disasm

CFLAGS		=	-I ../../include/ -I ./include -W -Wall -Wextra -Wshadow

CC		=	gcc

LDFLAGS		=	-L $(LIB) -lmy -lmy-printf -lget-next-line

RM		=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIB)my
	make -C $(LIB)my_printf
	make -C $(LIB)get_next_line
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make -C $(LIB)my clean
	make -C $(LIB)my_printf clean
	make -C $(LIB)get_next_line clean
	$(RM) $(OBJ)

fclean:		clean
	make -C $(LIB)my fclean
	make -C $(LIB)my_printf fclean
	make -C $(LIB)get_next_line fclean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)
	$(RM) *gc*

re:		fclean all
