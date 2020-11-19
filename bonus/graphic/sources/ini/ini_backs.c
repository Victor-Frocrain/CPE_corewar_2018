/*
** EPITECH PROJECT, 2019
** ini_backs
** File description:
** ini_backs
*/

#include "graphic.h"

void ini_backs(graphic_t *graphic)
{
    sfVector2f pos = {graphic->video.width / 2 - 338 / 2, 230};
    sfVector2f scale = {(1.0 / 1920) * graphic->video.width, \
(1.0 / 1080) * graphic->video.height};
    sfFloatRect rect;

    for (int i = 0; i < BACK; i++) {
        graphic->back[i].sprite = sfSprite_create();
        graphic->back[i].pos = pos;
        sfSprite_setTexture(graphic->back[i].sprite, \
graphic->back[i].texture, sfFalse);
        sfSprite_setScale(graphic->back[i].sprite, scale);
    }
    rect = sfSprite_getGlobalBounds(graphic->back[7].sprite);
    graphic->back[7].pos.x = graphic->video.width / 2 - rect.width / 2;
}
