/*
** EPITECH PROJECT, 2019
** graphic_loop
** File description:
** graphic_loop
*/

#include "graphic.h"
#include "corewar.h"

void manage_event(graphic_t *graphic)
{
    if (graphic->event.type == sfEvtClosed || \
graphic->event.key.code == sfKeyEscape) {
        sfRenderWindow_close(graphic->window);
    }
}

int graphic_loop(machine_t *machine)
{
    object_t empty[(int)REST];
    graphic_t graphic;
    bool is_end = false;

    srand(time(NULL));
    if (!ini_graphic(&graphic, empty))
        return (MY_ERROR);
    sfMusic_play(graphic.music[0]);
    while (sfRenderWindow_isOpen(graphic.window)) {
        if (!is_end)
            is_end = manage_scene(&graphic, empty, machine);
        else if (graphic.scene.over)
            display_over(&graphic);
        sfRenderWindow_display(graphic.window);
        if (sfRenderWindow_pollEvent(graphic.window, &graphic.event))
            manage_event(&graphic);
    }
    destroy_all(&graphic, empty);
    return (MY_SUCCESS);
}
