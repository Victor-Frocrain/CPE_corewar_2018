/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** write a character
*/

#include <unistd.h>

void my_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}
