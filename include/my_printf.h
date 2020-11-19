/*
** EPITECH PROJECT, 2019
** my_printf.h
** File description:
** my_printf.h
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include "my.h"

void my_printf(char *str, ...);
void my_printfd(int fd, char *str, ...);
void conv_base(int nb, int base, char c, int fd);
void my_put_no_printable_fd(char *str, int fd);
void my_put_unsigned_nbr_fd(unsigned int nb, int fd);
void my_putchar_fd(char c, int fd);
void my_putstr_fd(char *str, int fd);
void my_put_nbr_fd(int nb, int fd);

#endif /* MY_PRINTF_H_ */
