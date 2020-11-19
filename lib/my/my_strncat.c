/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** Copy [x1 ; x2] src at the end if str
*/

#include "my.h"

char *my_strncat(char *str, char *src, int x1, int x2)
{
    int length = my_strlen(str) + (x1 - x2) + 1;
    int i = 0;
    char *res = malloc(sizeof(char) * length);

    if (x2 < x1 || !str) {
        free(res);
        return (NULL);
    }
    for (; str[i]; i++)
        res[i] = str[i];
    for (; x1 < x2 && src[x1]; x1++) {
        res[i] = src[x1];
        i++;
    }
    res[i] = 0;
    return (res);
}
