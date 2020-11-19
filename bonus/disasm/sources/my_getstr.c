/*
** EPITECH PROJECT, 2019
** asm
** File description:
** my_getstr.c
*/

#include "disasm.h"

char *my_getstr(int nb)
{
    char *str = NULL;
    int i = 1;
    int mult = 1;
    int j = 0;
    bool is_neg = false;

    (nb < 0) ? (i++, is_neg = true):0;
    for (; nb / (mult * 10) > 0; i++, mult *= 10);
    str = malloc(sizeof(char) * (i + 1));
    if (str) {
        (is_neg) ? (str[j++] = '-'):0;
        for (; j < i; j++) {
            str[j] = (nb / mult) + '0';
            nb -= (nb / mult) * mult;
            mult /= 10;
        }
        str[j] = 0;
    }
    return (str);
}
