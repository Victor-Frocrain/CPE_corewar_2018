/*
** EPITECH PROJECT, 2019
** ini_images
** File description:
** ini_images
*/

#include "graphic.h"

void set_positions(graphic_t *graphic)
{
    sfIntRect rect = {0, 1236 - (1236 / 3 * 2), 811, 1236 / 3};
    sfIntRect rect2 = {0, 0, 70, 118 / 2};
    sfVector2f scale = {(0.2 / 1920) * graphic->video.width, \
(0.2 / 1080) * graphic->video.height};

    graphic->buttons[4].pos.x = (1040.0 / 1920) * graphic->video.width;
    graphic->buttons[4].pos.y = (100.0 / 1080) * graphic->video.height;
    graphic->buttons[5].pos.x = (1800.0 / 1920) * graphic->video.width;
    graphic->buttons[5].pos.y = (30.0 / 1080) * graphic->video.height;
    graphic->buttons[4].rect = rect;
    graphic->buttons[5].rect = rect2;
    sfSprite_setTextureRect(graphic->buttons[4].sprite, \
graphic->buttons[4].rect);
    sfSprite_setTextureRect(graphic->buttons[5].sprite, \
graphic->buttons[5].rect);
    sfSprite_setScale(graphic->buttons[4].sprite, scale);
    for (int i = 0; i < BUTTONS; i++) {
        sfSprite_setPosition(graphic->buttons[i].sprite, \
graphic->buttons[i].pos);
    }
}

void ini_buttons(graphic_t *graphic)
{
    sfVector2f pos = {graphic->video.width / 2 - ((338.0 / 1920) * \
graphic->video.width) / 2, (130.0 / 1080) * graphic->video.height};
    sfIntRect rect = {0, 381 - 381 / 3, 338, 381 / 3};
    sfVector2f scale = {(1.0 / 1920) * graphic->video.width, \
(1.0 / 1080) * graphic->video.height};

    for (int i = 0; i < BUTTONS; i++) {
        graphic->buttons[i].sprite = sfSprite_create();
        graphic->buttons[i].pos = pos;
        graphic->buttons[i].rect = rect;
        sfSprite_setTexture(graphic->buttons[i].sprite, \
graphic->buttons[i].texture, sfFalse);
        sfSprite_setTextureRect(graphic->buttons[i].sprite, \
graphic->buttons[i].rect);
        sfSprite_setScale(graphic->buttons[i].sprite, scale);
        pos.y += ((400.0) / 1920) * graphic->video.height;
    }
    graphic->buttons[6].pos.y = graphic->video.height - ((320.0 / 1920) * \
graphic->video.height);
    graphic->buttons[6].pos.x = (50.0 / 1920) * graphic->video.width;
}

void ini_volume(graphic_t *graphic)
{
    sfVector2f pos = {(200.0 / 1920) * graphic->video.width, \
(300.0 / 1080) * graphic->video.height};
    sfIntRect rect = {0, 0, 1500, 500};
    sfVector2f scale = {(1.0 / 1920) * graphic->video.width, \
(1.0 / 1080) * graphic->video.height};

    for (int i = 0; i < VOLUME; i++) {
        graphic->volume[i].sprite = sfSprite_create();
        graphic->volume[i].pos = pos;
        graphic->volume[i].rect = rect;
        sfSprite_setTexture(graphic->volume[i].sprite, \
graphic->volume[i].texture, sfFalse);
        sfSprite_setTextureRect(graphic->volume[i].sprite, \
graphic->volume[i].rect);
        sfSprite_setPosition(graphic->volume[i].sprite, \
graphic->volume[i].pos);
        rect.width -= 1500 / 2;
        sfSprite_setScale(graphic->volume[i].sprite, scale);
    }
}

bool ini_images(graphic_t *graphic)
{
    ini_textures(graphic);
    ini_buttons(graphic);
    ini_volume(graphic);
    ini_backs(graphic);
    set_positions(graphic);
    ini_stuff(graphic);
    ini_spark(graphic);
    ini_light(graphic);
    init_fireworks(graphic);
    return (ini_sounds(graphic));
}
