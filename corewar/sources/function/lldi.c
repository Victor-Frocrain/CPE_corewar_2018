/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** lldi.c
*/

#include "corewar.h"

void do_lldi(int to_store, int res[2], champion_t *champion, machine_t machine)
{
    int pc = champion->process->pc;
    int sum;
    char data[4];
    int value;

    sum = res[0] + res[1];
    add_pc(&pc, sum);
    for (int i = 0; i < REG_SIZE; i++) {
        data[i] = machine.map[pc];
        add_pc(&pc, 1);
    }
    value = get_val(data, false);
    champion->process->carry = value == 0;
    champion->process->registers[to_store] = value;
}

void f_lldi(machine_t *machine, champion_t *champion)
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
    do_lldi(to_store, res, champion, *machine);
    add_pc(pc, nb_byte);
}
