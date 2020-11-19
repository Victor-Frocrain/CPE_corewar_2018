/*
** EPITECH PROJECT, 2019
** my_str_isnum.c
** File description:
** Is str a number ?
*/

#include "my.h"

bool is_str_int(char *str)
{
    int i = 0;

    if (!str || !str[0])
        return (false);
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; str[i]; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (false);
    return (true);
}
