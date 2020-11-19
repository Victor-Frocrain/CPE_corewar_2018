/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** fill_instruct.c
*/

#include "corewar.h"

bool is_instruct_index(char c);

void fill_arg(int *pc, machine_t machine, char *arg, bool is_direct)
{
    int size = is_direct ? 4 : 2;

    for (int i = 0; i < size; i++) {
        arg[i] = machine.map[*pc];
        add_pc(pc, 1);
    }
}

void fill_mask_and_arg(int pc, machine_t machine, instruct_t *instruct, \
int size)
{
    int mem;
    int j = 0;
    bool is_index = is_instruct_index(instruct->code);

    add_pc(&pc, 2);
    for (int i = 3; i > 0; i--, j++) {
        mem = (size >> (i * 2)) & 0b11;
        instruct->mask[j] = mem;
        if (mem == 0b01) {
            instruct->arg[j][0] = machine.map[pc];
            add_pc(&pc, 1);
        }
        if (mem == 0b10)
            fill_arg(&pc, machine, instruct->arg[j], !is_index);
        if (mem == 0b11)
            fill_arg(&pc, machine, instruct->arg[j], false);
    }
}

int calc_nb_arg(int size)
{
    int res = 0;
    int mem;

    for (int i = 3; i > 0; i--) {
        mem = (size >> (i * 2)) & 0b11;
        if (mem == 0b01 || mem == 0b10 || mem == 0b11)
            res++;
    }
    return (res);
}

void fill_instruct(instruct_t *instruct, machine_t machine, int pc)
{
    int size = machine.map[(pc + 1) % MEM_SIZE];

    instruct->code = machine.map[pc];
    if (machine.map[pc] != 1 && machine.map[pc] != 9 && \
machine.map[pc] != 0X0c && machine.map[pc] != 0x0F) {
        instruct->nb_arg = calc_nb_arg(size);
        fill_mask_and_arg(pc, machine, instruct, size);
    } else {
        instruct->nb_arg = 1;
        instruct->mask[0] = 0b10;
        add_pc(&pc, 1);
        for (int i = 0; i < 4; i++) {
            instruct->arg[0][i] = machine.map[pc];
            add_pc(&pc, 1);
        }
    }
}
