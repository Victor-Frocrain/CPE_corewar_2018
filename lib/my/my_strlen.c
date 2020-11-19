/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** Count str size
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    if (!str)
        return (-1);
    for (; str && str[i]; i++);
    return (i);
}
