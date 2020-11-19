/*
** EPITECH PROJECT, 2019
** corewar graphic
** File description:
** display_menu
*/

#include "graphic.h"

void display_menu(graphic_t *graphic)
{
    sfRenderWindow_clear(graphic->window, sfBlack);
    for (int i = 2; i < 5; i++)
        sfRenderWindow_drawSprite\
(graphic->window, graphic->back[i].sprite, NULL);
    for (int i = 0; i < SPARK; i++)
        sfRenderWindow_drawSprite\
(graphic->window, graphic->spark[i].sprite, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite\
(graphic->window, graphic->buttons[i].sprite, NULL);
    }
}
