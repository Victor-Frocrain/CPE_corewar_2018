/*
** EPITECH PROJECT, 2019
** ini_objects
** File description:
** ini_objects
*/

#include "graphic.h"

void ini_color(sfColor *color)
{
    (*color).r = 255 / 2;
    (*color).g = 255 / 2;
    (*color).b = 255 / 2;
    (*color).a = 255;
}

bool ini_obj_text(graphic_t *graphic, int i, sfVector2f *pos, sfVector2f size)
{
    sfVector2f p_text = (*pos);

    graphic->cases[i].text = sfText_create();
    if (graphic->cases[i].text == NULL)
        return (false);
    p_text.y -= size.y / 4;
    sfText_setFont(graphic->cases[i].text, graphic->indic.font);
    sfText_setPosition(graphic->cases[i].text, p_text);
    sfText_setCharacterSize(graphic->cases[i].text, size.y);
    sfText_setColor(graphic->cases[i].text, sfWhite);
    sfText_setString(graphic->cases[i].text, "ff");
    (*pos).x += size.x + 1;
    if ((*pos).x + size.x + 1 >= graphic->video.width - \
(500.0 / 1920.0 * graphic->video.width)) {
        (*pos).x = 50;
        (*pos).y += size.y + 1;
    }
    return (true);
}

bool ini_rectangle(graphic_t *graphic, int i, sfVector2f size)
{
    static sfVector2f pos = {50, 50};

    graphic->cases[i].shape = sfRectangleShape_create();
    if (graphic->cases[i].shape == NULL)
        return (false);
    sfRectangleShape_setSize(graphic->cases[i].shape, size);
    sfRectangleShape_setPosition(graphic->cases[i].shape, pos);
    sfRectangleShape_setFillColor(graphic->cases[i].shape, sfWhite);
    return (ini_obj_text(graphic, i, &pos, size));
}

bool ini_rest(object_t *empty, int i, sfVector2f size, sfVector2f pos)
{
    empty[i].shape = sfRectangleShape_create();
    if (empty[i].shape == NULL)
        return (false);
    sfRectangleShape_setSize(empty[i].shape, size);
    sfRectangleShape_setPosition\
(empty[i].shape, pos);
    ini_color(&(empty[i].color));
    sfRectangleShape_setFillColor\
(empty[i].shape, empty[i].color);
    return (true);
}

bool ini_objects(graphic_t *graphic, object_t *empty)
{
    int bound = sqrtf(MEM_SIZE);
    float right = ((550.0 + bound) / 1920.0) * graphic->video.width;
    float top = ((100.0 + bound) / 1080.0) * graphic->video.height;
    sfVector2f size = {(graphic->video.width - right) / (bound), \
(graphic->video.height - top) / (bound)};
    sfVector2f pos;

    for (int i = 0; i < MEM_SIZE; i++)
        if (ini_rectangle(graphic, i, size) == false) {
            destroy_all(graphic, empty);
            return (false);
        }
    pos = sfRectangleShape_getPosition(graphic->cases[MEM_SIZE - 1].shape);
    for (int i = 0; i < REST; i++) {
        if (ini_rest(empty, i, size, pos) == false) {
            destroy_all(graphic, empty);
            return (false);
        }
        pos.x += size.x + 1;
    }
    return (ini_text(graphic));
}
