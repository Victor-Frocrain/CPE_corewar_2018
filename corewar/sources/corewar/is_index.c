/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** calc_size.c
*/

#include "corewar.h"

bool is_instruct_index(char c)
{
    return (c >= 0x09 && c <= 0x0F && c != 0x0D);
}
