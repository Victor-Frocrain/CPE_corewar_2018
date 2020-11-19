/*
** EPITECH PROJECT, 2019
** display_credits
** File description:
** display_credits
*/

#include "corewar.h"

void display_credits(graphic_t *graphic)
{
    sfRenderWindow_clear(graphic->window, sfBlack);
    sfRenderWindow_drawSprite(graphic->window, graphic->back[8].sprite, NULL);
    sfRenderWindow_drawSprite(graphic->window, graphic->back[7].sprite, NULL);
    sfRenderWindow_drawSprite(graphic->window, \
graphic->buttons[6].sprite, NULL);
}
