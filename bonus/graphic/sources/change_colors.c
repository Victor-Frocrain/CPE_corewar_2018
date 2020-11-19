/*
** EPITECH PROJECT, 2019
** change_colors
** File description:
** change_colors
*/

#include "graphic.h"

void change_colors(graphic_t *graphic, champion_t *champion, int pc)
{
    sfText_setColor(graphic->cases[pc].text, champion->color);
}
