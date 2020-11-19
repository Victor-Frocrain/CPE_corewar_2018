##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=		sources/corewar/corewar.c		\
			sources/corewar/loop.c			\
			sources/corewar/is_end.c		\
			sources/corewar/parser.c		\
			sources/corewar/fill_instruct.c		\
			sources/corewar/check_if_usage.c	\
			sources/corewar/open_file.c		\
			sources/corewar/fill_map.c		\
			sources/corewar/identify_flags.c	\
			sources/corewar/manage_params.c		\
			sources/corewar/get_value.c		\
			sources/corewar/dump.c			\
			sources/corewar/is_index.c		\
			sources/corewar/is_instruct_correct.c	\
			sources/reverse_nb.c			\
			sources/error.c				\
			sources/op.c				\
			sources/destroy/ressources.c		\

SRC_FUNC=		sources/function/func.c			\
			sources/function/ld.c			\
			sources/function/live.c			\
			sources/function/add.c			\
			sources/function/and.c			\
			sources/function/sub.c			\
			sources/function/or.c			\
			sources/function/xor.c			\
			sources/function/aff.c			\
			sources/function/zjmp.c			\
			sources/function/fork.c			\
			sources/function/lfork.c		\
			sources/function/lld.c			\
			sources/function/lldi.c			\
			sources/function/ldi.c			\
			sources/function/st.c			\
			sources/function/sti.c			\

SRC_TEST=		tests/filling_instruct.c		\
			tests/f_ldi.c				\
			tests/f_live.c				\
			tests/f_ld.c				\
			tests/f_lld.c				\
			tests/f_st.c				\
			tests/f_add.c				\
			tests/f_sub.c				\
			tests/f_and.c				\
			tests/f_or.c				\
			tests/f_xor.c				\
			tests/f_zjmp.c				\
			tests/f_aff.c				\
			tests/f_lldi.c				\
			tests/f_sti.c				\
			tests/f_fork.c				\
			tests/f_lfork.c				\
			tests/functional.c			\
			tests/testing_parser.c			\
			tests/testing_parser_val.c		\
			tests/parser_multiple_def.c		\
			tests/testing_opening_file.c		\
			tests/ending.c				\
			tests/parser_instruct.c			\

SRC_MAIN=		sources/main.c			\

OBJ	=		$(SRC:%.c=%.o) $(SRC_FUNC:%.c=%.o) $(SRC_MAIN:%.c=%.o)

LIB	=		../lib/

NAME	=		corewar

TEST_NAME	=	unit_test

CFLAGS	=		-I ../include/ -I ./include -W -Wall -Wextra -Wshadow

CC	=		gcc

LDFLAGS	=		-L $(LIB) -lmy -lmy-printf -lget-next-line

TEST_FLAGS	=	-lcriterion --coverage

RM	=		rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIB)/my
	make -C $(LIB)/my_printf
	make -C $(LIB)/get_next_line
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make -C $(LIB)/my clean
	make -C $(LIB)/my_printf clean
	make -C $(LIB)/get_next_line clean
	$(RM) $(OBJ)

fclean:		clean
	make -C $(LIB)/my fclean
	make -C $(LIB)/my_printf fclean
	make -C $(LIB)/get_next_line fclean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)
	$(RM) *.gc*

re:		fclean all

tests_run:
	make -C $(LIB)my/
	make -C $(LIB)my_printf/
	make -C $(LIB)get_next_line/
	$(CC) -o $(TEST_NAME) $(CFLAGS) $(SRC_TEST) $(SRC) $(SRC_FUNC) $(LDFLAGS) $(TEST_FLAGS)
	./$(TEST_NAME)
	gcovr --exclude tests
