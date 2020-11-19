/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** ldi.c
*/

#include "corewar.h"

int get_value(int i, process_t *process, machine_t *machine)
{
    int reg = process->instruct->arg[i][0] - 1;
    bool is_index = is_instruct_index(process->instruct->code);
    int pc = process->pc;

    if (process->instruct->mask[i] == REGISTER)
        return (process->registers[reg]);
    if (process->instruct->mask[i] == DIRECT) {
        if (is_index)
            return (get_val(process->instruct->arg[i], true));
        return (get_val(process->instruct->arg[i], false));
    }
    add_pc(&pc, get_val(process->instruct->arg[i], true));
    return (get_value_from_ind(pc, machine));
}

void do_ldi(int to_store, int res[2], champion_t *champion, machine_t machine)
{
    int pc = champion->process->pc;
    int sum;
    char data[4];
    int value;

    sum = (res[0] + res[1]) % IDX_MOD;
    add_pc(&pc, sum);
    for (int i = 0; i < REG_SIZE; i++) {
        data[i] = machine.map[pc];
        add_pc(&pc, 1);
    }
    value = get_val(data, false);
    champion->process->registers[to_store] = value;
    champion->process->carry = value == 0;
}

void f_ldi(machine_t *machine, champion_t *champion)
{
    int res[2];
    int to_store;
    int nb_byte = 3;
    short *mask = champion->process->instruct->mask;
    int *pc = &champion->process->pc;

    to_store = champion->process->instruct->arg[2][0] - 1;
    for (int i = 0; i < 2; i++) {
        res[i] = get_value(i, champion->process, machine);
        nb_byte += mask[i] == REGISTER ? 1 : 2;
    }
    do_ldi(to_store, res, champion, *machine);
    add_pc(pc, nb_byte);
}
