/*
** EPITECH PROJECT, 2019
** corewar graphic
** File description:
** display_settings
*/

#include "graphic.h"

void display_settings(graphic_t *graphic)
{
    sfRenderWindow_clear(graphic->window, sfBlack);
    sfRenderWindow_drawSprite(graphic->window, graphic->back[0].sprite, NULL);
    for (int i = 0; i < PARTICULES; i++)
        sfRenderWindow_drawSprite\
(graphic->window, graphic->stuff[i].sprite, NULL);
    for (int i = 0; i < VOLUME; i++)
        sfRenderWindow_drawSprite\
(graphic->window, graphic->volume[i].sprite, NULL);
    for (int i = 4; i < 7; i++)
        sfRenderWindow_drawSprite\
(graphic->window, graphic->buttons[i].sprite, NULL);
    for (int i = 6; i < 8; i++)
        sfRenderWindow_drawText(graphic->window, graphic->indic.text[i], NULL);
}
