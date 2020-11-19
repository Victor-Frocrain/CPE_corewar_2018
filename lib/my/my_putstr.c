/*
** EPITECH PROJECT, 2019
** my_put_str.c
** File description:
** displays characters
*/

#include "my.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
