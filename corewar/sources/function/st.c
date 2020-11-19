/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** ld.c
*/

#include "corewar.h"

void store_in_map(int data, char *arg, machine_t *machine, process_t *process)
{
    int pc = get_val(arg, true) % IDX_MOD;

    add_pc(&pc, process->pc);
    print_int_in_map(pc, machine, data);
}

void do_st(instruct_t *instruct, process_t *process, machine_t *machine)
{
    int data = process->registers[instruct->arg[0][0] - 1];
    int nb_byte = instruct->mask[1] == INDIRECT ? 5 : 4;

    if (instruct->mask[1] == INDIRECT)
        store_in_map(data, instruct->arg[1], machine, process);
    else
        process->registers[instruct->arg[1][0] - 1] = data;
    add_pc(&process->pc, nb_byte);
}

void f_st(machine_t *machine, champion_t *champion)
{
    do_st(champion->process->instruct, champion->process, machine);
}
