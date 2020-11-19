/*
** EPITECH PROJECT, 2019
** manage_volume
** File description:
** manage_volume
*/

#include "graphic.h"

void change_mute(graphic_t *graphic)
{
    if (graphic->buttons[5].rect.top == 0) {
        graphic->buttons[5].rect.top = 118 / 2;
        for (int i = 0; i < MUSIC; i++)
            sfMusic_setVolume(graphic->music[i], 0);
    }
    else {
        graphic->buttons[5].rect.top = 0;
        for (int i = 0; i < MUSIC; i++)
            sfMusic_setVolume(graphic->music[i], \
(float)graphic->volume[1].rect.width / 1500 * 100);
    }
    sfSprite_setTextureRect(graphic->buttons[5].sprite, \
graphic->buttons[5].rect);
}

void manage_mute(graphic_t *graphic)
{
    sfFloatRect bounds;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(graphic->window);
    sfVector2f pos;
    static bool click = false;

    bounds = sfSprite_getGlobalBounds(graphic->buttons[5].sprite);
    pos = graphic->buttons[5].pos;
    if (mouse.x >= pos.x && mouse.x <= pos.x + bounds.width &&  \
mouse.y >= pos.y && mouse.y <= pos.y + bounds.height && !graphic->is_clicked \
&& sfMouse_isButtonPressed(sfMouseLeft) && !click) {
        click = true;
        change_mute(graphic);
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft))
        click = false;
}

void manage_volume(graphic_t *graphic)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(graphic->window);
    sfFloatRect global = sfSprite_getGlobalBounds(graphic->volume[1].sprite);

    if (mouse.x >= global.left && \
mouse.x <= global.left + ((1500.0 / 1920) * graphic->video.width) && \
mouse.y >= (global.top) + global.height - (((float)(mouse.x)) / \
(graphic->video.width - global.left) * global.height) && \
mouse.y <= global.top + global.height && sfMouse_isButtonPressed(sfMouseLeft)) {
        graphic->volume[1].rect.width = mouse.x - global.left;
        sfSprite_setTextureRect\
(graphic->volume[1].sprite, graphic->volume[1].rect);
        for (int i = 0; i < MUSIC; i++) {
            sfMusic_setVolume(graphic->music[i], \
(float)graphic->volume[1].rect.width / 1500 * 100);
        }
    }
}
