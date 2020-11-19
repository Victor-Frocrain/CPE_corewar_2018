/*
** EPITECH PROJECT, 2019
** my_put_no_printable.c
** File description:
** Replace no printable char by a backslash
*/

#include "my_printf.h"

void print_tree_first_digit(char *str, int i, int fd)
{
    for (int j = 100; j >= 1; j /= 10) {
        if (str[i] / j == 0)
            my_putchar_fd('0', fd);
        else
            my_put_nbr_fd(str[i] / j, fd);
        str[i] %= j;
    }
}

void my_put_no_printable_fd(char *str, int fd)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= '!' && str[i] <= '~')
            my_putchar_fd(str[i], fd);
        else {
            my_putchar_fd('\\', fd);
            print_tree_first_digit(str, i, fd);
        }
    }
}
