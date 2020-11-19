/*
** EPITECH PROJECT, 2019
** my_put_unsigned_nbr.c
** File description:
** Print the unsigned intergers
*/

#include "my_printf.h"

void my_put_unsigned_nbr_fd(unsigned int nb, int fd)
{
    unsigned long mult = 1;
    int res;

    if (nb < 0) {
        my_putchar_fd('-', fd);
        nb *= -1;
    }
    for (; nb / mult >= 10; mult *= 10);
    for (; mult > 0; mult /= 10) {
        res = nb / mult;
        my_putchar_fd(res + '0', fd);
        nb -= res * mult;
    }
}
