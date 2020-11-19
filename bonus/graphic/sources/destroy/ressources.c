/*
** EPITECH PROJECT, 2019
** destroy_ressources
** File description:
** destroy_ressources
*/

#include "corewar.h"

void destroy_process(process_t *process)
{
    process_t *old_pro = process;

    if (process)
        process = process->next;
    for (; process; old_pro = process, process = process->next) {
        free(old_pro->instruct);
        free(old_pro);
    }
    if (old_pro) {
        free(old_pro->instruct);
        free(old_pro);
    }
}

void destroy_ressources(machine_t machine)
{
    for (int i = 0; i < machine.total; i++) {
        free(machine.champion[i]->file);
        free(machine.champion[i]->header);
        close(machine.champion[i]->fd);
        destroy_process(machine.champion[i]->process);
        free(machine.champion[i]);
    }
}
