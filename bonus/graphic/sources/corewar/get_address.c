/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** get_address.c
*/

#include "corewar.h"

int get_nb_from_bytecode(int nb, int size)
{
    if (nb > size / 2)
        return (nb - size - 1);
    return (nb);
}

int get_address(int pc, bool is_direct, int nb, bool is_idx_mod)
{
    int new_pc = is_direct ? 0 : pc;

    nb = is_direct ? reverse_int(nb) : reverse_short(nb);
    nb = get_nb_from_bytecode(nb, is_direct ? 0xFFFFFFFF : 0xFFFF);
    if (is_idx_mod)
        nb %= IDX_MOD;
    for (int i = 0; nb < 0 && i < -nb; i++)
        new_pc = decrement_val_mem_circ(new_pc);
    for (int i = 0; nb >= 0 && i < nb; i++)
        new_pc = increment_val_mem_circ(new_pc);
    return (new_pc);
}
