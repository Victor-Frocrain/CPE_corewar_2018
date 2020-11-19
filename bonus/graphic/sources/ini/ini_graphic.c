/*
** EPITECH PROJECT, 2019
** ini graphic
** File description:
** ini graphic
*/

#include "graphic.h"

void ini_scenes(graphic_t *graphic)
{
    graphic->scene.menu = true;
    graphic->scene.settings = false;
    graphic->scene.game = false;
    graphic->is_clicked = false;
    graphic->limit_round = 200;
    graphic->scene.begin = true;
    graphic->scene.over = false;
}

bool ini_graphic(graphic_t *graphic, object_t *empty)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        graphic->cases[i].shape = NULL;
        graphic->cases[i].text = NULL;
    }
    for (int i = 0; i < REST; i++)
        empty->shape = NULL;
    for (int i = 0; i < TEXT; i++)
        graphic->indic.text[i] = NULL;
    graphic->video = sfVideoMode_getDesktopMode();
    graphic->window = sfRenderWindow_create\
(graphic->video, "Corewar", sfFullscreen | sfResize | sfClose, NULL);
    if (!graphic->window)
        return (false);
    sfRenderWindow_setFramerateLimit(graphic->window, 60);
    graphic->indic.font = sfFont_createFromFile("images/space.ttf");
    graphic->clock = sfClock_create();
    if (graphic->indic.font == NULL)
        return (false);
    ini_scenes(graphic);
    return (ini_objects(graphic, empty));
}
