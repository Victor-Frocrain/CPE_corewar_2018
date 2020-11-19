/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** and.c
*/

#include "corewar.h"

int get_value_from_ind(int pc, machine_t *machine)
{
    char indirect[2];

    for (int i = 0; i < IND_SIZE; i++) {
        indirect[i] = machine->map[pc];
        add_pc(&pc, 1);
    }
    return (get_val(indirect, true));
}

void f_and(machine_t *machine, champion_t *champion)
{
    int to_store = champion->process->instruct->arg[2][0] - 1;
    int res[2];
    int nb_byte = 3;
    short *mask = champion->process->instruct->mask;

    for (int i = 0; i < 2; i++) {
        if (mask[i] == DIRECT)
            nb_byte += DIR_SIZE;
        else if (mask[i] == REGISTER)
            nb_byte++;
        else
            nb_byte += IND_SIZE;
        res[i] = get_value(i, champion->process, machine);
    }
    champion->process->registers[to_store] = res[0] & res[1];
    champion->process->carry = (res[0] & res[1]) == 0;
    add_pc(&champion->process->pc, nb_byte);
}
