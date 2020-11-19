/*
** EPITECH PROJECT, 2019
** display_over
** File description:
** display_over
*/

#include "corewar.h"

void display_over(graphic_t *graphic)
{
    sfRenderWindow_clear(graphic->window, sfBlack);
    sfRenderWindow_drawSprite(graphic->window, graphic->back[6].sprite, NULL);
    manage_fireworks(graphic);
    for (int i = 8; i < 10; i++)
        sfRenderWindow_drawText(graphic->window, graphic->indic.text[i], NULL);
}
