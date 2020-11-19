/*
** EPITECH PROJECT, 2019
** init_fireworks
** File description:
** init_fireworks
*/

#include "corewar.h"

void update_fire_positions(graphic_t *graphic, int i)
{
    sfVector2f pos;

    pos.x = rand() % (int)(graphic->video.width);
    pos.y = (200.0 / 1080) * graphic->video.height + \
rand() % (int)(graphic->video.height - (500.0 / 1080) * graphic->video.height);
    for (int j = 0; j < FIRE; j++) {
        graphic->fire[i][j].pos = pos;
        sfSprite_setPosition(graphic->fire[i][j].sprite, pos);
    }
}

int compute_way(void)
{
    int nb = rand() % 2;

    if (nb == 0)
        return (1);
    return (-1);
}

void change_pixel_colors(graphic_t *graphic, int i)
{
    sfUint8 pixel[4] = {180, 180, 180, 255};
    int time = sfTime_asMicroseconds(sfClock_getElapsedTime\
(graphic->clock));

    srand(time);
    pixel[rand() % 3] = 255;
    for (int k = 0; k < 3; k++)
        for (int height = 0; height < 3; height++)
            sfTexture_updateFromPixels(graphic->fire[i]->texture, \
pixel, 1, 1, k, height);
}

void fill_fire(graphic_t *graphic, int i)
{
    float incr = 1;
    float pos = 0;

    sfClock_restart(graphic->fire[i]->alive);
    change_pixel_colors(graphic, i);
    for (int j = 0; j < FIRE; j++, pos++) {
        if (pos >= 360)
            pos = 0;
        sfSprite_setTexture(graphic->fire[i][j].sprite, \
graphic->fire[i]->texture, sfTrue);
        graphic->fire[i][j].life = 950 + rand() % 2000;
        graphic->fire[i][j].dir.x = (1 + rand() % 20) * incr;
        graphic->fire[i][j].dir.y = ((rand() % 5 * \
(graphic->fire[i][j].dir.x)) * compute_way());
        graphic->fire[i][j].nb_alive = 1;
        sfClock_restart(graphic->fire[i][j].alive);
        incr *= -1;
    }
    update_fire_positions(graphic, i);
}

void init_fireworks(graphic_t *graphic)
{
    for (int i = 0; i < NB_FIRE; i++) {
        for (int j = 0; j < FIRE; j++) {
            graphic->fire[i]->texture = sfTexture_create(3, 3);
            graphic->fire[i][j].sprite = sfSprite_create();
            graphic->fire[i][j].alive = sfClock_create();
            graphic->fire[i][j].pixel[3] = 255;
            graphic->fire[i]->alive = sfClock_create();
        }
        fill_fire(graphic, i);
    }
}
