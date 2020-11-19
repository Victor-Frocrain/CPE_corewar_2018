##
## EPITECH PROJECT, 2019
## my_printf Makefile
## File description:
## my_printf Makefile
##

SRC	=	convert_base.c		\
		my_printf.c		\
		my_put_no_printable.c	\
		my_put_unsigned_nbr.c	\
		my_putchar.c		\
		my_putstr.c		\
		my_put_nbr.c		\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-I ../../include/

NAME	=	libmy-printf.a

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f ../$(NAME)

re:		fclean all
