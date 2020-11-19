/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** live.c
*/

#include "corewar.h"

void add_pc(int *pc, int nb)
{
    *pc +=nb;
    if (*pc < 0)
        *pc += MEM_SIZE;
    *pc %= MEM_SIZE;
}

void said_live(machine_t *machine, int nb)
{
    bool is_found = false;

    (*machine).nb_live++;
    for (int i = 0; !is_found && i < (*machine).total; i++) {
        if (nb == (*machine).champion[i]->number && \
(*machine).champion[i]->was_living) {
            machine->champion[i]->nb_live++;
            (*machine).champion[i]->is_alive = true;
            my_printf("The player %d(%s) is alive\n", nb, \
(*machine).champion[i]->header->prog_name);
            is_found = true;
        }
    }
}

void f_live(machine_t *machine, champion_t *champion)
{
    int direct = *(int *)(champion->process->instruct->arg[0]);

    said_live(machine, reverse_int(direct));
    add_pc(&champion->process->pc, 5);
}
