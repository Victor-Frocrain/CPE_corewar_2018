/*
** EPITECH PROJECT, 2019
** my_str_isprintable.c
** File description:
** Is str printable ?
*/

#include "my.h"

bool my_str_isprintable(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < ' ' || str[i] > '~')
            return (false);
    return (true);
}
