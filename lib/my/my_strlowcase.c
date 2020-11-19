/*
** EPITECH PROJECT, 2019
** my_strlowcase.c
** File description:
** Change upper case in lower case
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] -= 'A' - 'a';
    return (str);
}
