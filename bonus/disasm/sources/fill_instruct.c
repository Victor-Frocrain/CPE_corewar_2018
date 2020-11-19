/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** fill_instruct.c
*/

#include "disasm.h"

bool is_instruct_index(char c);

void fill_arg(char *arg, bool is_direct, char *file, int *pc)
{
    int size = is_direct ? 4 : 2;

    for (int i = 0; i < size; i++, (*pc)++)
        arg[i] = file[*pc];
}

void fill_mask_and_arg(instruct_t *instruct, int size, char *file)
{
    int mem;
    int j = 0;
    int pc = 2;
    bool is_index = is_instruct_index(instruct->code);

    for (int i = 3; i > 0; i--, j++) {
        mem = (size >> (i * 2)) & 0b11;
        instruct->mask[j] = mem;
        if (mem == REGISTER)
            instruct->arg[j][0] = file[pc++];
        if (mem == DIRECT)
            fill_arg(instruct->arg[j], !is_index, file, &pc);
        if (mem == INDIRECT)
            fill_arg(instruct->arg[j], false, file, &pc);
    }
}

int calc_nb_arg(int size)
{
    int res = 0;
    int mem;

    for (int i = 3; i > 0; i--) {
        mem = (size >> (i * 2)) & 0b11;
        if (mem == REGISTER || mem == DIRECT || mem == INDIRECT)
            res++;
    }
    return (res);
}

void fill_instruct(instruct_t *instruct, char *file)
{
    int size = file[1];

    instruct->code = file[0];
    if (file[0] != 1 && file[0] != 9 && file[0] != 0X0c && file[0] != 0x0F) {
        instruct->nb_arg = calc_nb_arg(size);
        fill_mask_and_arg(instruct, size, file);
    } else {
        instruct->nb_arg = 1;
        instruct->mask[0] = 0b10;
        for (int i = 0; i < 4; i++)
            instruct->arg[0][i] = file[i + 1];
    }
}
