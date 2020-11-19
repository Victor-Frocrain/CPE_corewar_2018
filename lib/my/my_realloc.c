/*
** EPITECH PROJECT, 2019
** my_realloc.c
** File description:
** Re allocate a space for str
*/

#include "my.h"

char *my_realloc(char *str, int nb)
{
    char *res = malloc(sizeof(char) * nb);
    int i = 0;

    if (!res || !str)
        return (NULL);
    for (; str[i] && i < nb; i++)
        res[i] = str[i];
    res[i] = 0;
    free(str);
    return (res);
}
