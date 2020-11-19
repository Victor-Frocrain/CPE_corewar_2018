/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** game loop
*/

#include "corewar.h"

void call_instruct(machine_t *machine, champion_t *champion, \
process_t *process, object_t *empty)
{
    int code;

    if (process->cumu_cycle == 1)
        fill_instruct(process->instruct, *machine, process->pc);
    code = process->instruct->code;
    if (is_instruct_correct(process->instruct)) {
        if (process->cumu_cycle >= op_tab[code - 1].nbr_cycles) {
            func[code - 1].func(machine, champion);
            process->cumu_cycle = 1;
            display_elements(machine->graphic, empty, machine);
            sfRenderWindow_display(machine->graphic->window);
            sfRenderWindow_clear(machine->graphic->window, sfBlack);
        } else
            process->cumu_cycle++;
    } else
        add_pc(&champion->process->pc, 1);
}

void manage_process(machine_t *machine, champion_t *champion, object_t *empty)
{
    process_t *next_process = champion->first_process;

    do {
        champion->process = next_process;
        next_process = next_process->next;
        call_instruct(machine, champion, champion->process, empty);
        change_colors(machine->graphic, champion, champion->process->pc);
    } while (next_process);
}

void manage_event(graphic_t *graphic);

void champions_action(machine_t *machine, object_t *empty)
{
    for (int i = 0; i < (*machine).total; i++) {
        if ((*machine).champion[i]->was_living)
            manage_process(machine, (*machine).champion[i], empty);
    }
    while ((*machine).nb_live >= NBR_LIVE) {
        (*machine).cycle_to_death -= CYCLE_DELTA;
        (*machine).nb_live -= NBR_LIVE;
    }
    if ((*machine).dump == (*machine).cycle)
        dump(*machine);
}

void tempo_grahic(machine_t *machine, graphic_t *graphic, object_t *empty)
{
    int time = sfTime_asMicroseconds(sfClock_getElapsedTime(graphic->clock));

    do {
        time = sfTime_asMicroseconds(sfClock_getElapsedTime(graphic->clock));
        if (sfRenderWindow_pollEvent(graphic->window, &graphic->event)) {
            manage_event(graphic);
            manage_mute(graphic);
            manage_buttons(graphic, 3, 4);
            manage_pause(graphic);
        }
    } while ((time < graphic->limit_round || graphic->pause) && \
sfRenderWindow_isOpen(graphic->window));
    if (time >= graphic->limit_round && \
sfRenderWindow_isOpen(graphic->window)) {
        champions_action(machine, empty);
        (*machine).cycle++;
        sfClock_restart(graphic->clock);
    }
}

void game_loop(machine_t *machine, graphic_t *graphic, object_t *empty)
{
    (*machine).graphic = graphic;
    add_champion_code_on_map(machine);
    while (!is_less_than_2_alive((*machine)) && \
sfRenderWindow_isOpen(graphic->window)) {
        for (int i = 0; i < (*machine).total; i++) {
            (*machine).champion[i]->was_living = \
(*machine).champion[i]->is_alive;
            (*machine).champion[i]->is_alive = false;
            (*machine).champion[i]->nb_live = 0;
        }
        for (int i = 0; i < (*machine).cycle_to_death && \
sfRenderWindow_isOpen(graphic->window); i++)
            tempo_grahic(machine, graphic, empty);
    }
    if (!graphic->scene.over) {
        manage_over(*machine);
        display_winner((*machine));
        graphic->scene.over = true;
    }
}
