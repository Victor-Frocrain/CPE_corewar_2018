/*
** EPITECH PROJECT, 2019
** manage_over
** File description:
** manage_over
*/

#include "corewar.h"

void set_victory_position(graphic_t *graphic)
{
    sfFloatRect bounds = sfText_getGlobalBounds(graphic->indic.text[8]);
    sfVector2f pos = {graphic->video.width / 2 - bounds.width / 2, \
(300.0 / 1080) * graphic->video.height};
    sfFloatRect bounds2 = sfText_getGlobalBounds(graphic->indic.text[9]);
    sfVector2f pos2 = {graphic->video.width / 2 - bounds2.width / 2, \
(400.0 / 1080) * graphic->video.height};

    sfText_setPosition(graphic->indic.text[8], pos);
    sfText_setPosition(graphic->indic.text[9], pos2);
}

void set_victory_size(graphic_t *graphic)
{
    int size1 = (70.0 / 1920) * graphic->video.width;
    int size2 = (45.0 / 1920) * graphic->video.width;

    sfText_setCharacterSize(graphic->indic.text[8], size1);
    sfText_setCharacterSize(graphic->indic.text[9], size2);
    set_victory_position(graphic);
}

void set_victory_string(graphic_t *graphic, int nb_winner, \
champion_t **champion)
{
    char *str = "THE CHAMPION ";

    sfText_setString(graphic->indic.text[8], "SURVIVOR(S) :");
    for (int i = 0; i < nb_winner; i++) {
        str = my_strcat(str, my_getstr(champion[i]->number));
        str = my_strcat(str, " : ");
        str = my_strcat(str, champion[i]->header->prog_name);
        str = my_strcat(str, "\n");
    }
    sfText_setString(graphic->indic.text[9], str);
    set_victory_size(graphic);
}

void manage_over(machine_t machine)
{
    int nb_winner = count_winner(machine);
    champion_t *champion[nb_winner > 0 ? nb_winner : machine.total];

    nb_winner = nb_winner > 0 ? nb_winner : machine.total;
    for (int j = 0, i = 0; j < machine.total; j++) {
        if (nb_winner > 1 && machine.champion[j]->was_living)
            champion[i++] = machine.champion[j];
        if (nb_winner == 1 && machine.champion[j]->is_alive)
            champion[i++] = machine.champion[j];
    }
    set_victory_string(machine.graphic, nb_winner, champion);
}
