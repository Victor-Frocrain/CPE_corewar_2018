/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** live.c
*/

#include "corewar.h"

void f_aff(machine_t *machine, champion_t *champion)
{
    int to_load = champion->process->instruct->arg[0][0];
    int data = champion->process->registers[to_load];

    if (machine)
        my_putchar(data % 256);
    add_pc(&champion->process->pc, 3);
}
