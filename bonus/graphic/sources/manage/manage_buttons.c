/*
** EPITECH PROJECT, 2019
** manage_buttons
** File description:
** manage_buttons
*/

#include "graphic.h"

void check_click(graphic_t *graphic)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        graphic->is_clicked = true;
    else
        graphic->is_clicked = false;
}

void identify_button(graphic_t *graphic, int i)
{
    sfVector2f pos = {(1500.0 / 1920) * graphic->video.width, \
(850.0 / 1080) * graphic->video.height};

    if (i == 0)
        begin_game(graphic, pos);
    if (i == 1) {
        graphic->scene.menu = false;
        graphic->scene.settings = true;
    }
    if (i == 2) {
        graphic->back[7].pos.y = graphic->video.height;
        graphic->scene.menu = false;
        graphic->scene.credits = true;
    }
    if (i == 3)
        sfRenderWindow_close(graphic->window);
    if (i == 6) {
        graphic->scene.menu = true;
        graphic->scene.settings = false;
        graphic->scene.credits = false;
    }
}

void activate_button(graphic_t *graphic, int i)
{
    if (graphic->is_clicked && !sfMouse_isButtonPressed(sfMouseLeft)) {
        graphic->is_clicked = false;
        identify_button(graphic, i);
    }
}

void detect_if_isclicked(graphic_t *graphic, int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        graphic->buttons[i].rect.top = 0;
        graphic->is_clicked = true;
    }
    else {
        graphic->buttons[i].rect.top = 381 / 3;
        graphic->is_clicked = false;
    }
}

void manage_buttons(graphic_t *graphic, int min, int max)
{
    sfFloatRect bounds;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(graphic->window);
    sfVector2f pos;
    bool on_button = false;

    for (int i = min; i < max; i++) {
        bounds = sfSprite_getGlobalBounds(graphic->buttons[i].sprite);
        pos = graphic->buttons[i].pos;
        if (mouse.x >= pos.x && mouse.x <= pos.x + bounds.width && \
mouse.y >= pos.y && mouse.y <= pos.y + bounds.height) {
            activate_button(graphic, i);
            detect_if_isclicked(graphic, i);
            on_button = true;
        }
        else
            graphic->buttons[i].rect.top = 381 - 381 / 3;
        sfSprite_setTextureRect(graphic->buttons[i].sprite, \
graphic->buttons[i].rect);
    }
    if (on_button == false)
        graphic->is_clicked = false;
}
