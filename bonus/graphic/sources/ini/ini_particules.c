/*
** EPITECH PROJECT, 2019
** ini_particules
** File description:
** ini_particules
*/

#include "graphic.h"

void reset_left(graphic_t *graphic)
{
    sfFloatRect rect;

    graphic->back[4].size.x = (0.45 / 1920) * graphic->video.width;
    graphic->back[4].size.y = (0.45 / 1080) * graphic->video.height;
    sfSprite_setScale(graphic->back[4].sprite, graphic->back[4].size);
    rect = sfSprite_getGlobalBounds(graphic->back[4].sprite);
    graphic->back[4].pos.x = (915.0 / 1920) * graphic->video.width - rect.width;
    graphic->back[4].speed = (9.0 / 1920) * graphic->video.width;
}

void update_left(graphic_t *graphic)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(graphic->back[4].sprite);
    sfVector2f zoom = {(0.0015 / 1920) * graphic->video.width, \
(0.0015 / 1080) * graphic->video.height};

    if (graphic->back[4].pos.x + rect.width <= 0)
        reset_left(graphic);
    else {
        graphic->back[4].pos.x -= graphic->back[4].speed;
        graphic->back[4].pos.y -= graphic->back[4].speed;
        graphic->back[4].size.x += zoom.x * graphic->back[4].speed;
        graphic->back[4].size.y += zoom.y * graphic->back[4].speed;
        sfSprite_setScale(graphic->back[4].sprite, graphic->back[4].size);
        graphic->back[4].speed++;
    }
    rect = sfSprite_getGlobalBounds(graphic->back[4].sprite);
    graphic->back[4].pos.y = (525.0 / 1080) * graphic->video.height - \
rect.height / 2;
    sfSprite_setPosition(graphic->back[4].sprite, graphic->back[4].pos);
}

void reset_right(graphic_t *graphic)
{
    graphic->back[3].pos.x = (1005.0 / 1920) * graphic->video.width;
    graphic->back[3].size.x = (0.5 / 1920) * graphic->video.width;
    graphic->back[3].size.y = (0.5 / 1080) * graphic->video.height;
    graphic->back[3].speed = (1.0 / 1920) * graphic->video.width;
}

void update_light(graphic_t *graphic)
{
    sfFloatRect rect;
    sfVector2f zoom = {(0.0023 / 1920) * graphic->video.width, \
(0.0023 / 1080) * graphic->video.height};

    if (graphic->back[3].pos.x >= graphic->video.width)
        reset_right(graphic);
    else {
        graphic->back[3].pos.x += graphic->back[3].speed;
        graphic->back[3].pos.y -= graphic->back[3].speed;
        graphic->back[3].size.x += zoom.x * graphic->back[3].speed;
        graphic->back[3].size.y += zoom.y * graphic->back[3].speed;
        graphic->back[3].speed++;
    }
    sfSprite_setScale(graphic->back[3].sprite, graphic->back[3].size);
    rect = sfSprite_getGlobalBounds(graphic->back[3].sprite);
    graphic->back[3].pos.y = (525.0 / 1080) * graphic->video.height - \
rect.height / 2;
    sfSprite_setPosition(graphic->back[3].sprite, graphic->back[3].pos);
    update_left(graphic);
}

void ini_light(graphic_t *graphic)
{
    sfColor color = {255, 255, 255, 50};
    sfVector2f scale = {(0.5 / 1920) * graphic->video.width, \
(0.5 / 1080) * graphic->video.height};
    sfFloatRect rect;
    sfVector2f pos = {(1005.0 / 1920) * graphic->video.width, 0};

    for (int i = 3; i < 5; i++) {
        graphic->back[i].size = scale;
        sfSprite_setScale(graphic->back[i].sprite, scale);
        rect = sfSprite_getGlobalBounds(graphic->back[i].sprite);
        pos.y = (525.0 / 1080) * graphic->video.height - rect.height / 2;
        graphic->back[i].pos = pos;
        sfSprite_setColor(graphic->back[i].sprite, color);
        sfSprite_setPosition(graphic->back[i].sprite, pos);
        pos.x = (915.0 / 1920) * graphic->video.width - rect.width;
        scale.x = (0.45 / 1920) * graphic->video.width;
        scale.y = (0.45 / 1080) * graphic->video.height;
    }
    graphic->back[3].speed = (1.0 / 1920) * graphic->video.width;
    graphic->back[4].speed = (9.0 / 1920) * graphic->video.width;
}
