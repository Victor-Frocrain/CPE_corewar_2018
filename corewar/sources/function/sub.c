/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** live.c
*/

#include "corewar.h"

int get_from_reg(char arg[5], champion_t *champion);

void f_sub(machine_t *machine, champion_t *champion)
{
    int f_sub = get_from_reg(champion->process->instruct->arg[0], champion);
    int s_sub = get_from_reg(champion->process->instruct->arg[1], champion);
    int to_store = champion->process->instruct->arg[2][0] - 1;

    if (machine)
        champion->process->registers[to_store] = f_sub - s_sub;
    champion->process->carry = (f_sub - s_sub) == 0;
    add_pc(&champion->process->pc, 5);
}
