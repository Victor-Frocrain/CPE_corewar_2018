/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** ld.c
*/

#include "corewar.h"

void do_lld(process_t *process, instruct_t *instruct, machine_t *machine)
{
    int to_store = instruct->arg[1][0] - 1;
    int data;
    int nb_byte = instruct->mask[0] == DIRECT ? 7 : 5;
    int indir;

    if (instruct->mask[0] == DIRECT)
        data = get_val(instruct->arg[0], false);
    else {
        indir = get_val(instruct->arg[0], true);
        data = load_data(process, machine, indir);
    }
    process->registers[to_store] = data;
    process->carry = data == 0;
    add_pc(&process->pc, nb_byte);
}

void f_lld(machine_t *machine, champion_t *champion)
{
    do_lld(champion->process, champion->process->instruct, machine);
}
