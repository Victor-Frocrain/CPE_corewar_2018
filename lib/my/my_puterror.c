/*
** EPITECH PROJECT, 2019
** my_puterror.c
** File description:
** Print string in error canal
*/

#include "my.h"

void my_puterror(char *str)
{
    for (int i = 0; str[i]; i++)
        write(2, &str[i], 1);
}
