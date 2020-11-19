/*
** EPITECH PROJECT, 2019
** manage_scene
** File description:
** manage_scene
*/

#include "corewar.h"

void game_loop(machine_t *machine, graphic_t *graphic, object_t *empty);

void manage_credits(graphic_t *graphic)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(graphic->back[7].sprite);

    manage_mute(graphic);
    manage_buttons(graphic, 6, 7);
    if (graphic->back[7].pos.y >= -bounds.height + (900.0 / 1080) * \
graphic->video.height)
        graphic->back[7].pos.y -= 2;
    sfSprite_setPosition(graphic->back[7].sprite, graphic->back[7].pos);
    display_credits(graphic);
    sfRenderWindow_drawSprite(graphic->window, \
graphic->buttons[5].sprite, NULL);
}

void manage_settings(graphic_t *graphic)
{
    if (graphic->scene.settings) {
        manage_mute(graphic);
        manage_volume(graphic);
        update_time(graphic);
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(graphic->clock)) \
>= 25) {
            update_stuff(graphic);
            sfClock_restart(graphic->clock);
        }
        manage_buttons(graphic, 6, 7);
        display_settings(graphic);
        sfRenderWindow_drawSprite(graphic->window, \
graphic->buttons[5].sprite, NULL);
    }
}

bool manage_scene(graphic_t *graphic, object_t *empty, machine_t *machine)
{
    if (graphic->scene.menu) {
        manage_mute(graphic);
        manage_buttons(graphic, 0, 4);
        update_light(graphic);
        update_spark(graphic);
        display_menu(graphic);
        sfRenderWindow_drawSprite(graphic->window, \
graphic->buttons[5].sprite, NULL);
    }
    manage_settings(graphic);
    if (graphic->scene.credits)
        manage_credits(graphic);
    if (graphic->scene.game)
        game_loop(machine, graphic, empty);
    if (graphic->scene.over)
        display_over(graphic);
    return (graphic->scene.game);
}
