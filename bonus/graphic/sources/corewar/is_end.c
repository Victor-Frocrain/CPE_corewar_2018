/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** is_end.c
*/

#include "corewar.h"

bool is_less_than_2_alive(machine_t machine)
{
    int count_alive = 0;

    for (int i = 0; i < machine.total; i++)
        if (machine.champion[i]->is_alive)
            count_alive++;
    return (count_alive <= 1);
}

int count_winner(machine_t machine)
{
    int res = 0;

    for (int i = 0; i < machine.total; i++)
        if (machine.champion[i]->is_alive)
            res++;
    if (res == 0)
        for (int i = 0; i < machine.total; i++)
            res = (machine.champion[i]->is_alive) ? res + 1: res;
    return (res);
}

void display_winner(machine_t machine)
{
    int nb_winner = count_winner(machine);
    champion_t *champion[nb_winner > 0 ? nb_winner : machine.total];

    nb_winner = nb_winner > 0 ? nb_winner : machine.total;
    for (int j = 0, i = 0; j < machine.total; j++) {
        if (nb_winner > 1 && machine.champion[j]->was_living)
            champion[i++] = machine.champion[j];
        if (nb_winner == 1 && machine.champion[j]->is_alive)
            champion[i++] = machine.champion[j];
    }
    if (nb_winner == 1)
        my_printf("The player %d(%s) has won\n", champion[0]->number, \
champion[0]->header->prog_name);
    else {
        my_printf("Equality between %d(%s)", champion[0]->number, \
champion[0]->header->prog_name);
        for (int j = 1; j < nb_winner; j++)
            my_printf(", %d(%s)", champion[j]->number, \
champion[j]->header->prog_name);
        my_putchar('\n');
    }
}
