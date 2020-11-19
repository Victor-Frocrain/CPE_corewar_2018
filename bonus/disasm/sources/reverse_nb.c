/*
** EPITECH PROJECT, 2019
** asm
** File description:
** int_as_byte_code.c
*/

#include "disasm.h"

int reverse_short(int nb)
{
    int res = (nb & 0xFF00) >> 8;

    res |= (nb & 0x00FF) << 8;
    return (res);
}

int reverse_int(int nb)
{
    int res = 0;

    res |= (nb & 0xFF000000) >> (4 * 6);
    res |= (nb & 0x00FF0000) >> (4 * 2);
    res |= (nb & 0x0000FF00) << (4 * 2);
    res |= (nb & 0x000000FF) << (4 * 6);
    return (res);
}
