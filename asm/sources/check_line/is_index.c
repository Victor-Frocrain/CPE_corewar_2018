/*
** EPITECH PROJECT, 2019
** asm
** File description:
** is_index.c
*/

#include "asm.h"

bool is_instruct_index(char *str)
{
    if (my_strcmp("ldi", str))
        return (true);
    if (my_strcmp("sti", str))
        return (true);
    if (my_strcmp("zjmp", str))
        return (true);
    if (my_strcmp("fork", str))
        return (true);
    if (my_strcmp("lfork", str))
        return (true);
    if (my_strcmp("lldi", str))
        return (true);
    return (false);
}
