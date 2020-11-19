/*
** EPITECH PROJECT, 2019
** update_time
** File description:
** update_time
*/

#include "graphic.h"

void update_time(graphic_t *graphic)
{
    char *tim = NULL;

    graphic->buttons[4].rect.top = 1236 - 1236 / 3 * 2;
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        graphic->limit_round++;
        graphic->buttons[4].rect.top = 1236 - 1236 / 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && graphic->limit_round > 0) {
        graphic->limit_round--;
        graphic->buttons[4].rect.top = 0;
    }
    tim = my_strcat("Time between each cycle (in milliseconds) : ", \
my_getstr(graphic->limit_round));
    sfSprite_setTextureRect(graphic->buttons[4].sprite, \
graphic->buttons[4].rect);
    if (!tim)
        return;
    sfText_setString(graphic->indic.text[6], tim);
    free(tim);
}
