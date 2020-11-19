/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** sti.c
*/

#include "corewar.h"

void print_int_in_map(int pc, machine_t *machine, int nb, champion_t *champion)
{
    for (int i = 3; i >= 0; i--) {
        change_colors(machine->graphic, champion, pc);
        (*machine).map[pc] = (nb >> (8 * i)) & 0xFF;
        add_pc(&pc, 1);
    }
}

void do_sti(int to_load, int res[2], champion_t *champion, machine_t *machine)
{
    int pc = champion->process->pc;
    int sum;

    sum = (res[0] + res[1]) % IDX_MOD;
    add_pc(&pc, sum);
    print_int_in_map(pc, machine, champion->process->registers[to_load], \
champion);
}

void f_sti(machine_t *machine, champion_t *champion)
{
    int res[2];
    int to_load;
    int nb_byte = 3;
    short *mask = champion->process->instruct->mask;

    to_load = champion->process->instruct->arg[0][0] - 1;
    for (int i = 0; i < 2; i++) {
        res[i] = get_value(i + 1, champion->process, machine);
        nb_byte += mask[i + 1] == REGISTER ? 1 : 2;
    }
    do_sti(to_load, res, champion, machine);
    add_pc(&champion->process->pc, nb_byte);
}
