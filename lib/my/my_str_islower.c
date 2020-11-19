/*
** EPITECH PROJECT, 2019
** my_str_islower.c
** File description:
** Is str only lower case ?
*/

#include "my.h"

bool my_str_islower(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 'a' || str[i] > 'z')
            return (false);
    return (true);
}
