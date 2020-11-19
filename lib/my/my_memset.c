/*
** EPITECH PROJECT, 2019
** my_memset.c
** File description:
** Setup the memory
*/

#include "my.h"

void my_memset(char *str, char c, int nb)
{
    int i = 0;

    for (; i < nb; i++)
        str[i] = c;
    str[i] = 0;
}
