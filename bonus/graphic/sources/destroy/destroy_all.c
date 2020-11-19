/*
** EPITECH PROJECT, 2019
** destroy_all
** File description:
** destroy_all
*/

#include "graphic.h"

void destroy_sounds(graphic_t *graphic)
{
    for (int i = 0; i < MUSIC; i++) {
        if (graphic->music[i]) {
            sfMusic_stop(graphic->music[i]);
            sfMusic_destroy(graphic->music[i]);
        }
    }
}

void destroy_images(graphic_t *graphic)
{
    for (int i = 0; i < BUTTONS; i++) {
        if (graphic->buttons[i].sprite)
            sfSprite_destroy(graphic->buttons[i].sprite);
        if (graphic->buttons[i].texture)
            sfTexture_destroy(graphic->buttons[i].texture);
    }
}

void destroy_all(graphic_t *graphic, object_t *empty)
{
    int i = 0;

    destroy_images(graphic);
    destroy_sounds(graphic);
    for (i = 0; i < MEM_SIZE && graphic->cases[i].shape != NULL; i++);
    for (i--; i >= 0; i--)
        sfRectangleShape_destroy(graphic->cases[i].shape);
    for (i = 0; i < MEM_SIZE && graphic->cases[i].text != NULL; i++);
    for (i--; i >= 0; i--)
        sfText_destroy(graphic->cases[i].text);
    for (i = 0; i < REST && empty[i].shape != NULL; i++);
    for (i--; i >= 0; i--)
        sfRectangleShape_destroy(empty[i].shape);
    for (i = 0; i < TEXT && graphic->indic.text[i] != NULL; i++);
    for (i--; i >= 0; i--)
        sfText_destroy(graphic->indic.text[i]);
    if (graphic->indic.font)
        sfFont_destroy(graphic->indic.font);
    if (graphic->window)
        sfRenderWindow_destroy(graphic->window);
}
