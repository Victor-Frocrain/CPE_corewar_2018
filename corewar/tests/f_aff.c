/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** aff.c
*/

#include "corewar.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

champion_t *ini_champ(machine_t *machine);

Test(Corewar, aff_i, .init = redirect_all_std)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 0;
    machine.champion[0]->process->registers[0] = 'i';
    f_aff(&machine, machine.champion[0]);
    cr_expect_stdout_eq_str("i");
    cr_expect_eq(machine.champion[0]->process->pc, 3);
}

Test(Corewar, aff_i_with_modulo, .init = redirect_all_std)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 0;
    machine.champion[0]->process->registers[0] = 'i' + (256 * 2);
    f_aff(&machine, machine.champion[0]);
    cr_expect_stdout_eq_str("i");
    cr_expect_eq(machine.champion[0]->process->pc, 3);
}
