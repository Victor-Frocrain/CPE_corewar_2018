/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** my_printf
*/

#include "my_printf.h"
#include <stdarg.h>

void print_conv_base(char *str, va_list list, int i, int fd)
{
    if (str[i] == 'b')
        conv_base(va_arg(list, int), 2, '0', fd);
    if (str[i] == 'x')
        conv_base(va_arg(list, int), 16, 'a', fd);
    if (str[i] == 'X')
        conv_base(va_arg(list, int), 16, 'A', fd);
    if (str[i] == 'o')
        conv_base(va_arg(list, int), 8, '0', fd);
    if (str[i] == 'p')
        conv_base(va_arg(list, int), 16, '0', fd);
}

void main_manage_mod(char *str, va_list list, int i, int fd)
{
    if (str[i] == 's')
        my_putstr_fd(va_arg(list, char *), fd);
    if (str[i] == 'S')
        my_put_no_printable_fd(va_arg(list, char *), fd);
    if (str[i] == 'c')
        my_putchar_fd(va_arg(list, int), fd);
    if (str[i] == 'd' || str[i] == 'i')
        my_put_nbr_fd(va_arg(list, int), fd);
    if (str[i] == 'u')
        my_put_unsigned_nbr_fd(va_arg(list, unsigned int), fd);
    if (str[i] == '%')
        my_putchar_fd('%', fd);
    print_conv_base(str, list, i, fd);
}

void my_printf(char *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            main_manage_mod(str, list, i + 1, 1);
            i++;
        } else
            my_putchar_fd(str[i], 1);
    }
    va_end(list);
}

void my_printfd(int fd, char *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            main_manage_mod(str, list, i + 1, fd);
            i++;
        } else
            my_putchar_fd(str[i], fd);
    }
    va_end(list);
}
