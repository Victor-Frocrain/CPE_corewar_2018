/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** testing_is_end.c
*/

#include "corewar.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

champion_t *ini_champ(machine_t *machine);

Test(Corewar, draw, .init = redirect_all_std)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[1] = ini_champ(&machine);
    machine.champion[0]->was_living = true;
    machine.champion[1]->was_living = true;
    display_winner(machine);
    cr_assert_stdout_eq_str("Equality between 1(zork), 1(zork)\n");
}

Test(Corewar, one_winner, .init = redirect_all_std)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[1] = ini_champ(&machine);
    machine.champion[0]->is_alive = true;
    machine.champion[1]->was_living = true;
    display_winner(machine);
    cr_assert_stdout_eq_str("The player 1(zork) has won\n");
}
