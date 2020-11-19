/*
** EPITECH PROJECT, 2019
** Corewar
** File description:
** corewar.c
*/

#include "corewar.h"

machine_t init_machine(void)
{
    machine_t machine;

    for (int i = 0; i < MAX_ARGS_NUMBER; i++)
        machine.champion[i] = NULL;
    machine.dump = -1;
    machine.cycle_to_death = CYCLE_TO_DIE;
    machine.nb_live = 0;
    machine.total = 0;
    machine.cycle = 1;
    my_memset(machine.map, 0, MEM_SIZE);
    return (machine);
}

void fill_register(champion_t **champion, machine_t machine)
{
    for (int i = 0; i < machine.total; i++) {
        champion[i]->process->registers[0] = machine.champion[i]->number;
        champion[i]->process->registers[1] = machine.champion[i]->process->pc;
        for (int j = 2; j < REG_NUMBER; j++)
            champion[i]->process->registers[j] = 0;
    }
}

int corewar(int ac, char **av)
{
    machine_t machine = init_machine();
    bool is_error = false;

    if (check_if_usage(ac, av) == true)
        return (MY_SUCCESS);
    if (!is_error)
        is_error = parser(av, &machine);
    if (!is_error)
        is_error = fill_champ_value_uninitialized(&machine);
    if (!is_error) {
        fill_register(machine.champion, machine);
        is_error = graphic_loop(&machine) == MY_ERROR;
        destroy_ressources(machine);
    }
    if (is_error)
        my_puterror("\033[0;m");
    return (is_error ? MY_ERROR : MY_SUCCESS);
}
