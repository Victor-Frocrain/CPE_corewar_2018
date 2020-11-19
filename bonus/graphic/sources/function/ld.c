/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** ld.c
*/

#include "corewar.h"

int load_data(process_t *process, machine_t *machine, int to_add)
{
    char reg[4];
    int pc = process->pc;

    add_pc(&pc, to_add);
    for (int i = 0; i < REG_SIZE; i++) {
        reg[i] = machine->map[pc];
        add_pc(&pc, 1);
    }
    return (get_val(reg, false));
}

void do_ld(process_t *process, instruct_t *instruct, machine_t *machine)
{
    int to_store = instruct->arg[1][0] - 1;
    int data;
    int nb_byte = instruct->mask[0] == DIRECT ? 7 : 5;
    int ind;

    if (instruct->mask[0] == INDIRECT) {
        ind = get_val(instruct->arg[0], true) % IDX_MOD;
        data = load_data(process, machine, ind);
    } else
        data = get_val(instruct->arg[0], false);
    process->registers[to_store] = data;
    process->carry = data == 0;
    add_pc(&process->pc, nb_byte);
}

void f_ld(machine_t *machine, champion_t *champion)
{
    do_ld(champion->process, champion->process->instruct, machine);
}
