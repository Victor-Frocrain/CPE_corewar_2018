/*
** EPITECH PROJECT, 2019
** begin_game
** File description:
** begin_game
*/

#include "graphic.h"

void begin_game(graphic_t *graphic, sfVector2f pos)
{
    graphic->scene.game = true;
    graphic->scene.menu = false;
    sfMusic_stop(graphic->music[0]);
    graphic->buttons[3].pos = pos;
    sfSprite_setPosition(graphic->buttons[3].sprite, pos);
    sfMusic_play(graphic->music[1]);
}
