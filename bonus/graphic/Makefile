##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_CORE=		sources/corewar/corewar.c		\
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
			sources/display_credits.c		\

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

SRC	=		sources/ini/ini_objects.c		\
			sources/ini/ini_sounds.c		\
			sources/ini/ini_backs.c			\
			sources/ini/ini_particules.c		\
			sources/ini/ini_textures.c		\
			sources/ini/ini_text.c			\
			sources/ini/ini_stuff.c			\
			sources/ini/ini_spark.c			\
			sources/ini/ini_images.c		\
			sources/ini/ini_graphic.c		\
			sources/begin_game.c			\
			sources/graphic_loop.c			\
			sources/is_mem_pos_pc.c			\
			sources/display_elements.c		\
			sources/display_text.c			\
			sources/display_settings.c		\
			sources/display_menu.c			\
			sources/change_colors.c			\
			sources/my_getstr.c			\
			sources/update_time.c			\
			sources/manage/manage_scene.c		\
			sources/manage/manage_buttons.c		\
			sources/manage/manage_volume.c		\
			sources/manage/manage_over.c		\
			sources/manage/manage_pause.c		\
			sources/display_over.c			\
			sources/destroy/destroy_all.c		\
			sources/manage_fireworks.c		\
			sources/init_fireworks.c		\

SRC_MAIN=		sources/main.c		\

OBJ	=		$(SRC:%.c=%.o) $(SRC_MAIN:%.c=%.o) $(SRC_FUNC:%.c=%.o) $(SRC_CORE:%.c=%.o)

LIB	=		../../lib/

NAME	=		corewar

CFLAGS	=		-I ../../include -I ./include -W -Wall -Wextra -Wshadow

CC	=		gcc

LDFLAGS	=		-L $(LIB) -lmy -lmy-printf -lget-next-line -lcsfml-audio \
-lcsfml-window -lcsfml-system -lcsfml-graphics

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
	$(RM) *.gc*

re:		fclean all
