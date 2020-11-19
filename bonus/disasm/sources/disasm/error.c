/*
** EPITECH PROJECT, 2019
** asm
** File description:
** error.c
*/

#include "disasm.h"

void print_error_color(char *color, char *str, bool is_bold)
{
    my_puterror((is_bold) ? "\033[1;" : "\033[0;");
    my_puterror(color);
    my_puterror("m");
    my_puterror(str);
}

void print_line_error_color(char *str, int nb_line)
{
    char *nb = my_getstr(nb_line);
    char *res;

    if (nb) {
        res = my_strcat("Line ", nb);
        if (res) {
            print_error_color(C_MAGENTA, res, true);
            my_puterror(": ");
            my_puterror(str);
            free(res);
        }
        free(nb);
    }
}
