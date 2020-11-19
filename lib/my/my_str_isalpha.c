/*
** EPITECH PROJECT, 2019
** my_str_isalpha.c
** File description:
** Is str only alphabetical
*/

#include "my.h"

bool my_str_isalpha(char *str)
{
    for (int i = 0; str[i]; i++)
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z')))
            return (false);
    return (true);
}
