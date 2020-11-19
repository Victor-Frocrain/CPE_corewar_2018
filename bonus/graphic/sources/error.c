/*
** EPITECH PROJECT, 2019
** asm
** File description:
** error.c
*/

#include "corewar.h"

void print_error_color(char *color, char *str)
{
    my_puterror("\033[1;");
    my_puterror(color);
    my_puterror("m");
    my_puterror(str);
}
