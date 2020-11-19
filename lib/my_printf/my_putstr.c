/*
** EPITECH PROJECT, 2019
** my_put_str.c
** File description:
** displays characters
*/

#include "my_printf.h"

void my_putstr_fd(char *str, int fd)
{
    if (!str)
        return;
    write(fd, str, my_strlen(str));
}
