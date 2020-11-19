##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	sources/asm/parser.c			\
			sources/asm/create_cor_file.c		\
			sources/asm/read_files.c		\
			sources/asm/create_instruct_arg.c	\
			sources/asm/int_as_byte_code.c		\
			sources/asm/compile_and_write.c		\
			sources/asm/write_prog.c		\
			sources/asm/write_instruct.c		\
			sources/asm/calc_label_dist.c		\
			sources/check_line/manage_instruct.c	\
			sources/check_line/manage_dot.c		\
			sources/check_line/manage_op.c		\
			sources/check_line/check_arg_type.c	\
			sources/check_line/is_duplicate_label.c	\
			sources/check_line/is_index.c		\
			sources/op.c				\
			sources/asm/error.c			\
			sources/my_getstr.c			\
			sources/destroy/data.c			\

SRC_TEST	=	tests/argument_parser.c		\
			tests/create_cor_files.c	\
			tests/filter_instruction.c	\
			tests/get_dot.c			\
			tests/convert_int.c		\
			tests/fill_instruct_arg.c	\
			tests/writting_instruction.c	\
			tests/writting_type.c		\
			tests/functional.c		\
			tests/manage_dot_error.c	\
			tests/arg_type_error.c		\
			tests/manage_op_error.c		\
			tests/label_dist.c		\
			tests/duplicate_label.c		\
			tests/index.c			\
			tests/is_dot.c			\
			tests/read_line.c		\

SRC_MAIN	=	sources/main.c		\

OBJ		=	$(SRC:%.c=%.o) $(SRC_MAIN:%.c=%.o) $(SRC_MNEMONIC:%.c=%.o)

LIB		=	../lib/

NAME		=	asm

TEST_NAME	=	unit_test

CFLAGS		=	-I ../include/ -I ./include -W -Wall -Wextra -Wshadow

CC		=	gcc

LDFLAGS		=	-L $(LIB) -lmy -lmy-printf -lget-next-line

TEST_FLAGS	=	-lcriterion --coverage

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

tests_run:
	make -C $(LIB)my/
	make -C $(LIB)my_printf/
	make -C $(LIB)get_next_line/
	$(CC) -o $(TEST_NAME) $(CFLAGS) $(SRC_TEST) $(SRC) $(SRC_MNEMONIC) $(LDFLAGS) $(TEST_FLAGS)
	./$(TEST_NAME)
	gcovr --exclude tests

