/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** fork.c
*/

#include "corewar.h"

instruct_t *ini_instruct(void)
{
    instruct_t *instruct = malloc(sizeof(instruct_t));

    if (instruct) {
        instruct->code = -1;
        instruct->nb_arg = -1;
        for (int i = 0; i < 3; i++) {
            instruct->mask[i] = 0;
            instruct->arg[i][0] = 0;
            instruct->arg[i][1] = 0;
            instruct->arg[i][2] = 0;
            instruct->arg[i][3] = 0;
            instruct->arg[i][4] = 0;
        }
    }
    return (instruct);
}

void f_fork(machine_t *machine, champion_t *champion)
{
    process_t *process = malloc(sizeof(process_t));
    process_t *last_process = champion->process;
    bool is_error = !process;
    char *arg = champion->process->instruct->arg[0];

    if (!is_error)
        is_error = !(process->instruct = ini_instruct());
    if (!is_error && machine) {
        champion->nb_process++;
        for (; last_process->next; last_process = last_process->next);
        process->next = NULL;
        for (int i = 0; i < REG_NUMBER; i++)
            process->registers[i] = champion->process->registers[i];
        process->cumu_cycle = 1;
        process->pc = champion->process->pc;
        process->carry = champion->process->carry;
        add_pc(&process->pc, get_val(arg, true) % IDX_MOD);
        last_process->next = process;
        add_pc(&champion->process->pc, 3);
    }
}
