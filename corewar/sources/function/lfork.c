/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** lfork.c
*/

#include "corewar.h"

instruct_t *ini_instruct(void);

void f_lfork(machine_t *machine, champion_t *champion)
{
    process_t *process = malloc(sizeof(process_t));
    process_t *last_process = champion->process;
    bool is_error = !process;
    char *arg = champion->process->instruct->arg[0];

    if (!is_error)
        is_error = !(process->instruct = ini_instruct());
    if (!is_error && machine) {
        for (; last_process->next; last_process = last_process->next);
        process->next = NULL;
        for (int i = 0; i < REG_NUMBER; i++)
            process->registers[i] = champion->process->registers[i];
        process->cumu_cycle = 1;
        process->pc = champion->process->pc;
        process->carry = champion->process->carry;
        add_pc(&process->pc, get_val(arg, true));
        last_process->next = process;
        add_pc(&champion->process->pc, 3);
    }
}
