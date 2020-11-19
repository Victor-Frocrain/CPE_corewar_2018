/*
** EPITECH PROJECT, 2019
** manage_pause
** File description:
** manage_pause
*/

#include "graphic.h"

void manage_pause(graphic_t *graphic)
{
    static bool is_key_pressed = false;

    if (sfKeyboard_isKeyPressed(sfKeySpace))
        is_key_pressed = true;
    if (!sfKeyboard_isKeyPressed(sfKeySpace) && is_key_pressed) {
        graphic->pause = !graphic->pause;
        is_key_pressed = false;
    }
}
