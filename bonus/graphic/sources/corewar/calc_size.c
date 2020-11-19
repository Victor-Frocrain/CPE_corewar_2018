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

bool is_no_size(int code)
{
    return (code == 1 || code == 9 || code == 15 || code == 12);
}

bool is_right_param(int code, char mask)
{
    int mem;

    for (int i = 0; i < op_tab[code].nbr_args; i++) {
        mem = mask >> -(i - 3) * 2;
        mem &= 0b11;
        if (mem == 0b01 && (op_tab[code].type[i] & T_REG) == 0)
            return (false);
        if (mem == 0b10 && (op_tab[code].type[i] & T_DIR) == 0)
            return (false);
        if (mem == 0b11 && (op_tab[code].type[i] & T_IND) == 0)
            return (false);
    }
    return (true);
}

int calc_size(char code, char size)
{
    int res = 0;
    int mem;
    bool is_index = is_instruct_index(code);
    int codes = code - 1;

    if (is_no_size(code))
        return (is_index ? 3 : 5);
    if (!(codes >= 0 && codes <= 15) || !is_right_param(code - 1, size))
        return (-1);
    for (int i = 0; i < op_tab[codes].nbr_args; i++) {
        mem = size >> -(i - 3) * 2;
        mem &= 0b11;
        if (mem == 0b01)
            res++;
        if (mem == 0b10 && !is_index)
            res += 4;
        if (mem == 0b11 || (is_index && mem == 0b10))
            res += 2;
    }
    return (res != 0 ? res + 2 : -1);
}
