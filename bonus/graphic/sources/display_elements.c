/*
** EPITECH PROJECT, 2019
** display_elements
** File description:
** display_elements
*/

#include "graphic.h"

void get_char_hexa(int nb, char res[2]);

void display_square(graphic_t *graphic, object_t *empty, machine_t *machine)
{
    char hexa[3];

    hexa[2] = 0;
    for (int i = 0; i < MEM_SIZE; i++) {
        if (is_mem_pos_pc(machine, i))
            sfRenderWindow_drawRectangleShape(graphic->window, \
graphic->cases[i].shape, NULL);
        get_char_hexa((*machine).map[i], hexa);
        sfText_setString(graphic->cases[i].text, hexa);
        sfRenderWindow_drawText(graphic->window, graphic->cases[i].text, NULL);
    }
    for (int i = 3; i < 7; i += 2)
        sfRenderWindow_drawSprite(graphic->window, graphic->buttons[i].sprite, \
NULL);
}

void display_elements(graphic_t *graphic, object_t *empty, machine_t *machine)
{
    sfRenderWindow_drawSprite(graphic->window, graphic->back[1].sprite, NULL);
    display_square(graphic, empty, machine);
    display_info(machine);
}
