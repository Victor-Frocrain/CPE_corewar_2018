/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** Convert the number hidden in str in interger
*/

#include "my.h"

int my_getnbr(char *str)
{
    int nb = 0;
    int i = 0;
    int mult = 1;
    bool neg = false;

    if (str[i] == '-' || str[i] == '+' || str[i] == ' ') {
        if (str[i] == '-')
            neg = true;
        i++;
    }
    for (int j = i; str[j + 1]; j++)
        mult *= 10;
    for (; str[i]; i++) {
        nb += mult * (str[i] - '0');
        mult /= 10;
    }
    if (neg)
        nb *= (-1);
    return (nb);
}
