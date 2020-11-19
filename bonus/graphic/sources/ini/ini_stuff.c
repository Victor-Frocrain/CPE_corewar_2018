/*
** EPITECH PROJECT, 2019
** ini_stuff
** File description:
** ini_stuff
*/

#include "graphic.h"

void update_pixel_sprite(particule_t *stuff)
{
    for (unsigned int x = 0; x < 2; x++) {
        for (unsigned int y = 0; y < 2; y++)
            sfTexture_updateFromPixels\
(stuff->texture, stuff->pixel, 1, 1, x, y);
    }
}

void ini_stuff(graphic_t *graphic)
{
    for (int i = 0; i < PARTICULES; i++) {
        graphic->stuff[i].pixel[0] = rand() % 255;
        graphic->stuff[i].pixel[1] = rand() % 255;
        graphic->stuff[i].pixel[2] = rand() % 255;
        graphic->stuff[i].pixel[3] = 255;
        graphic->stuff[i].alive = sfClock_create();
        graphic->stuff[i].texture = sfTexture_create(2, 2);
        graphic->stuff[i].sprite = sfSprite_create();
        update_pixel_sprite(&graphic->stuff[i]);
        sfSprite_setTexture\
(graphic->stuff[i].sprite, graphic->stuff[i].texture, sfFalse);
        graphic->stuff[i].pos.x = rand() % graphic->video.width;
        graphic->stuff[i].pos.y = (rand() % (int)((1000.0 / 1080) \
* graphic->video.height));
        graphic->stuff[i].dir.x = 0;
        graphic->stuff[i].dir.y = (1 + rand() % 20) * -1;
        graphic->stuff[i].life = 500 + (rand() % 10000);
    }
}

void reset_stuff(graphic_t *graphic, int i)
{
    graphic->stuff[i].pixel[0] = rand() % 255;
    graphic->stuff[i].pixel[1] = rand() % 255;
    graphic->stuff[i].pixel[2] = rand() % 255;
    sfClock_restart(graphic->stuff[i].alive);
    graphic->stuff[i].life = 500 + (rand() % 10000);
    update_pixel_sprite(&graphic->stuff[i]);
    sfSprite_setTexture\
(graphic->stuff[i].sprite, graphic->stuff[i].texture, sfFalse);
    graphic->stuff[i].pos.x = rand() % graphic->video.width;
    graphic->stuff[i].pos.y = (rand() % (int)(graphic->video.height));
    graphic->stuff[i].dir.x = 0;
    graphic->stuff[i].dir.y = (1 + rand() % 20) * -1;
}

void update_stuff(graphic_t *graphic)
{
    for (int i = 0; i < PARTICULES; i++) {
        if (graphic->stuff[i].pos.y <= 0 || sfTime_asMilliseconds\
(sfClock_getElapsedTime(graphic->clock)) >= graphic->stuff[i].life)
            reset_stuff(graphic, i);
        else {
            graphic->stuff[i].pos.x += graphic->stuff[i].dir.x;
            graphic->stuff[i].pos.y += graphic->stuff[i].dir.y;
        }
        sfSprite_setPosition(graphic->stuff[i].sprite, \
graphic->stuff[i].pos);
    }
}
