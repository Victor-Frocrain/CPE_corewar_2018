/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** Is str2 under str1 ?
*/

#include "my.h"

bool my_strcmp(char *s1, char *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return (false);
    for (; s1[i] && s2[i]; i++)
        if (s1[i] != s2[i])
            return (false);
    if (s1[i] != s2[i])
        return (false);
    return (true);
}
