/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** game loop
*/

#include "corewar.h"

void call_instruct(machine_t *machine, champion_t *champion, process_t *process)
{
    int code;

    if (process->cumu_cycle == 1)
        fill_instruct(process->instruct, *machine, process->pc);
    code = process->instruct->code;
    if (is_instruct_correct(process->instruct)) {
        if (process->cumu_cycle >= op_tab[code - 1].nbr_cycles) {
            func[code - 1].func(machine, champion);
            process->cumu_cycle = 1;
        } else
            process->cumu_cycle++;
    } else
        add_pc(&process->pc, 1);
}

void manage_process(machine_t *machine, champion_t *champion)
{
    for (; champion->process; champion->process = champion->process->next)
        call_instruct(machine, champion, champion->process);
    champion->process = champion->first_process;
}

bool champions_action(machine_t *machine)
{
    for (int i = 0; i < (*machine).total; i++) {
        if ((*machine).champion[i]->was_living)
            manage_process(machine, (*machine).champion[i]);
    }
    while ((*machine).nb_live >= NBR_LIVE) {
        (*machine).cycle_to_death -= CYCLE_DELTA;
        (*machine).nb_live -= NBR_LIVE;
    }
    if ((*machine).dump == (*machine).cycle) {
        dump(*machine);
        return (true);
    }
    return (false);
}

void game_loop(machine_t *machine)
{
    bool is_dumped = false;

    while (!is_less_than_2_alive((*machine)) && !is_dumped) {
        for (int i = 0; i < (*machine).total; i++) {
            (*machine).champion[i]->was_living = \
(*machine).champion[i]->is_alive;
            (*machine).champion[i]->is_alive = false;
        }
        for (int i = 0; i < (*machine).cycle_to_death && !is_dumped; i++, \
(*machine).cycle++)
            is_dumped = champions_action(machine);
    }
    if (!is_dumped)
        display_winner((*machine));
}
