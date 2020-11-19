/*
** EPITECH PROJECT, 2019
** graphic corewar
** File description:
** is_mem_pos_pc
*/

#include "graphic.h"

bool is_mem_pos_pc(machine_t *machine, int pos)
{
    bool found = false;
    process_t *process;

    for (int i = 0; !found && i < machine->total; i++) {
        process = machine->champion[i]->first_process;
        for (; !found && process->next; process = process->next)
            found = (process->pc == pos);
    }
    return (found);
}
