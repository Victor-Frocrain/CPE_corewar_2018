/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** get_value.c
*/

#include "corewar.h"

int get_val(char *arg, bool is_short)
{
    short little;

    if (is_short) {
        little = reverse_short(*(short *)(arg));
        return (little);
    }
    return (reverse_int(*(int *)(arg)));
}
