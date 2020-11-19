/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** Copy the string in other allocation space
*/

#include "my.h"

char *my_strcpy(char *src)
{
    char *res = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    if (!res || !src)
        return (NULL);
    for (; src && src[i]; i++)
        res[i] = src[i];
    res[i] = 0;
    return (res);
}
