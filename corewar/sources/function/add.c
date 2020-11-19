/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** live.c
*/

#include "corewar.h"

int get_from_reg(char arg[5], champion_t *champion)
{
    int reg = arg[0] - 1;

    return (champion->process->registers[reg]);
}

void f_add(machine_t *machine, champion_t *champion)
{
    int f_add = get_from_reg(champion->process->instruct->arg[0], champion);
    int s_add = get_from_reg(champion->process->instruct->arg[1], champion);
    int to_store = champion->process->instruct->arg[2][0] - 1;

    if (machine)
        champion->process->registers[to_store] = f_add + s_add;
    champion->process->carry = (f_add + s_add) == 0;
    add_pc(&champion->process->pc, 5);
}
