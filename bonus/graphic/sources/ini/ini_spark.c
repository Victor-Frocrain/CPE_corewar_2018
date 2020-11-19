/*
** EPITECH PROJECT, 2019
** ini_spark
** File description:
** ini_spark
*/

#include "graphic.h"

void ini_spark(graphic_t *graphic)
{
    for (int i = 0; i < SPARK; i++) {
        graphic->spark[i].pixel[0] = 255;
        graphic->spark[i].pixel[1] = 255;
        graphic->spark[i].pixel[2] = 200;
        graphic->spark[i].pixel[3] = 255;
        graphic->spark[i].alive = sfClock_create();
        graphic->spark[i].texture = sfTexture_create(2, 2);
        graphic->spark[i].sprite = sfSprite_create();
        update_pixel_sprite(&graphic->spark[i]);
        sfSprite_setTexture\
(graphic->spark[i].sprite, graphic->spark[i].texture, sfFalse);
        graphic->spark[i].pos.x = 0;
        graphic->spark[i].pos.y = 0;
        graphic->spark[i].dir.x = (1 + (rand() % 3)) * -1;
        graphic->spark[i].dir.y = (1 + rand() % 3);
        graphic->spark[i].life = 100 + (rand() % 800);
    }
}

void reset_spark(graphic_t *graphic, int i)
{
    sfClock_restart(graphic->spark[i].alive);
    graphic->spark[i].life = 100 + (rand() % 800);
    update_pixel_sprite(&graphic->spark[i]);
    sfSprite_setTexture\
(graphic->spark[i].sprite, graphic->spark[i].texture, sfFalse);
    graphic->spark[i].pos.x = (1312.0 / 1920) * graphic->video.width;
    graphic->spark[i].pos.y = (466.0 / 1080) * graphic->video.height;
    graphic->spark[i].dir.x = 0;
    graphic->spark[i].dir.y = 0;
}

void update_spark(graphic_t *graphic)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(graphic->back[3].sprite);
    sfVector2f pos = {(1312.0 / 1920) * graphic->video.width, \
(466.0 / 1080) * graphic->video.height};

    for (int i = 0; i < SPARK; i++) {
        if (graphic->back[3].pos.x + rect.width >= (1312.0 / 1920) * \
graphic->video.width && graphic->spark[i].pos.x == pos.x && \
graphic->spark[i].pos.y == pos.y) {
            graphic->spark[i].dir.x = (1 + (rand() % 3)) * -1;
            graphic->spark[i].dir.y = (1 + rand() % 3);
        }
        if (sfTime_asMilliseconds\
(sfClock_getElapsedTime(graphic->spark[i].alive)) >= graphic->spark[i].life)
            reset_spark(graphic, i);
        else {
            graphic->spark[i].pos.x += graphic->spark[i].dir.x;
            graphic->spark[i].pos.y += graphic->spark[i].dir.y;
        }
        sfSprite_setPosition(graphic->spark[i].sprite, \
graphic->spark[i].pos);
    }
}
