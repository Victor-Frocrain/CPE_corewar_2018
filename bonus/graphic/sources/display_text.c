/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** display_text.c
*/

#include "corewar.h"

void display_text(graphic_t *graphic, sfVector2f pos, char *str, sfColor color)
{
    sfText_setColor(graphic->indic.text[0], color);
    sfText_setPosition(graphic->indic.text[0], pos);
    sfText_setString(graphic->indic.text[0], str);
    sfRenderWindow_drawText(graphic->window, graphic->indic.text[0], NULL);
}

void display_info_champ(champion_t *champion, sfVector2f pos, \
machine_t *machine)
{
    char *name = my_strcat("Name : ", champion->header->prog_name);
    char *nb_process = my_strcat("Nb process : ", \
my_getstr(champion->nb_process));
    char *nb_live = my_strcat("Nb live : ", my_getstr(champion->nb_live));
    char *living = champion->was_living ? "Alive" : "Dead";

    display_text(machine->graphic, pos, name, champion->color);
    pos.y += 20;
    display_text(machine->graphic, pos, nb_process, champion->color);
    pos.y += 20;
    display_text(machine->graphic, pos, nb_live, champion->color);
    pos.y += 20;
    display_text(machine->graphic, pos, living, champion->color);
    free(name);
    free(nb_live);
    free(nb_process);
}

void display_info(machine_t *machine)
{
    sfVector2f pos = {(1450.0 / 1920) * machine->graphic->video.width, \
(100.0 / 1080) * machine->graphic->video.height};
    char *cycle = my_strcat("Total cycle : ", my_getstr(machine->cycle));
    char *cycle_to_die = my_strcat("Cycle to die : ", \
my_getstr(machine->cycle_to_death));

    display_text(machine->graphic, pos, cycle, sfWhite);
    pos.y += 40;
    display_text(machine->graphic, pos, cycle_to_die, sfWhite);
    pos.y += 40;
    for (int i = 0; i < machine->total; i++) {
        display_info_champ(machine->champion[i], pos, machine);
        pos.y += 100;
    }
    free(cycle);
    free(cycle_to_die);
}
