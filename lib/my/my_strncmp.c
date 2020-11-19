/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** Is str2 under str1 [x1 ; x2] ?
*/

#include "my.h"

bool my_strncmp(char *s1, char *s2, int x1, int x2)
{
    if (x1 >= x2)
        return (false);
    for (; s1[x1] && s2[x1] && x1 < x2; x1++)
        if (s1[x1] != s2[x1])
            return (false);
    if (s1[x1] != s2[x1])
        return (false);
    return (true);
}
