/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** Copy [x1 ; x2] from str in other allocated space
*/

#include "my.h"

char *my_strncpy(char *str, int x1, int x2)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    if (x1 > x2 || !res || !str) {
        if (res)
            free(res);
        return (NULL);
    }
    for (; str[x1] && x1 < x2; x1++, i++)
        res[i] = str[x1];
    res[x2] = 0;
    return (res);
}
