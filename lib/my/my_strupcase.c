/*
** EPITECH PROJECT, 2019
** my_strupcase.c
** File description:
** Change lower case in upper case
*/

#include "my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] += 'A' - 'a';
    return (str);
}
