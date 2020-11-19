/*
** EPITECH PROJECT, 2019
** my_str_isupper.c
** File description:
** Is str only upper case ?
*/

#include "my.h"

bool my_str_isupper(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 'A' || str[i] > 'Z')
            return (false);
    return (true);
}
