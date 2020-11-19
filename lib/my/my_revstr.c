/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** Reverse the string
*/

#include "my.h"

char *my_revstr(char *str)
{
    char mem;
    int size = my_strlen(str);
    int j = size - 1;

    for (int i = 0; i < size / 2; i++) {
        mem = str[i];
        str[i] = str[j];
        str[j] = mem;
        j--;
    }
    return (str);
}
