/*
** EPITECH PROJECT, 2019
** ini_sounds
** File description:
** ini_sounds
*/

#include "graphic.h"

bool ini_sounds(graphic_t *graphic)
{
    graphic->music[0] = sfMusic_createFromFile("sounds/menu3.ogg");
    graphic->music[1] = sfMusic_createFromFile("sounds/battle.ogg");
    graphic->music[2] = sfMusic_createFromFile("sounds/win.ogg");
    for (int i = 0; i < MUSIC; i++) {
        if (!graphic->music[i])
            return (false);
        sfMusic_setLoop(graphic->music[i], sfTrue);
        sfMusic_setVolume(graphic->music[i], 50);
    }
    return (true);
}
