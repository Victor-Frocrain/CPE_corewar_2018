/*
** EPITECH PROJECT, 2019
** my_strcapitalize.c
** File description:
** Change the begin of str in cap
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i]; i++)
        if ((i == 0 || (str[i - 2] == '.' && str[i - 1] == ' '))
            && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] += 'A' - 'a';
    return (str);
}
