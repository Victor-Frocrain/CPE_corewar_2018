/*
** EPITECH PROJECT, 2019
** convert_base.c
** File description:
** Convert every base and choose wich char if base is sup as 10
*/

#include "my_printf.h"

int power(int base, int pow)
{
    int result = base;

    if (pow == 0)
        return (1);
    if (pow == 1)
        return (result);
    for (; pow >= 2; pow--)
        result *= base;
    return (result);
}

int cumu_power(int base, int pow)
{
    int result = 0;

    for (; pow >= 0; pow--)
        result += power(base, pow + 1);
    return (result);
}

int searching_max_power(int nb, int base, int pow)
{
    float result = nb;

    result /= power(base, pow);
    if (result >= 1)
        return (searching_max_power(nb, base, pow + 1));
    return (pow - 1);
}

void conv_base(int nb, int base, char c, int fd)
{
    int pow = searching_max_power(nb, base, 0);
    int result[pow];
    int i = 0;

    if (base < 2)
        return;
    for (; pow >= 0; pow--) {
        result[pow] = nb / power(base, pow);
        nb %= power(base, pow);
        i++;
    }
    i--;
    for (; i >= 0; i--) {
        if (result[i] >= 0 && result[i] <= 9)
            my_putchar_fd(result[i] + '0', fd);
        else
            my_putchar_fd(result[i] + c - 10, fd);
    }
}
