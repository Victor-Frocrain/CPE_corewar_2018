/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** zjmp.c
*/

#include "corewar.h"

void f_zjmp(machine_t *machine, champion_t *champion)
{
    char *arg = champion->process->instruct->arg[0];

    if (champion->process->carry && machine)
        add_pc(&champion->process->pc, get_val(arg, true) % IDX_MOD);
    else
        add_pc(&champion->process->pc, 3);
}
