/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** fill_map.c
*/

#include "corewar.h"

void add_champ(machine_t *machine, champion_t *champion)
{
    int j = champion->process->pc;

    for (int i = 0; i < champion->header->prog_size; i++) {
        change_colors(machine->graphic, champion, j);
        (*machine).map[j] = champion->file[i];
        add_pc(&j, 1);
    }
}

void add_champion_code_on_map(machine_t *machine)
{
    for (int i = 0; i < (*machine).total; i++) {
        add_champ(machine, (*machine).champion[i]);
        machine->champion[i]->nb_live = 0;
        machine->champion[i]->nb_process = 1;
    }
}
