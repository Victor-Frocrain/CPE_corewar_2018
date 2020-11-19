/*
** EPITECH PROJECT, 2019
** manage_fireworks
** File description:
** manage_fireworks
*/

#include "corewar.h"

void move_fireworks(graphic_t *graphic, int i, int elapsed)
{
    int time = 0;

    for (int j = 0; j < FIRE; j++) {
        time = sfTime_asMilliseconds(sfClock_getElapsedTime\
(graphic->fire[i][j].alive)) - elapsed;
        if (time < graphic->fire[i][j].life) {
            sfRenderWindow_drawSprite(graphic->window, \
graphic->fire[i][j].sprite, NULL);
            graphic->fire[i][j].pos.x += graphic->fire[i][j].dir.x;
            graphic->fire[i][j].pos.y += graphic->fire[i][j].dir.y;
            sfSprite_setPosition(graphic->fire[i][j].sprite, \
graphic->fire[i][j].pos);
        }
        else
            graphic->fire[i][j].nb_alive = 0;
    }
}

bool check_if_reset(graphic_t *graphic, int i)
{
    int total = 0;

    for (int j = 0; j < FIRE; j++)
        total += graphic->fire[i][j].nb_alive;
    if (total == 0)
        return (true);
    return (false);
}

void manage_fireworks(graphic_t *graphic)
{
    bool reset = false;
    int time = 0;

    for (int i = 0; i < NB_FIRE; i++) {
        reset = check_if_reset(graphic, i);
        if (reset) {
            fill_fire(graphic, i);
        }
        time = sfTime_asMilliseconds(sfClock_getElapsedTime\
(graphic->fire[i]->alive));
        if (time >= 200 * i)
            move_fireworks(graphic, i, 200 * i);
    }
}
