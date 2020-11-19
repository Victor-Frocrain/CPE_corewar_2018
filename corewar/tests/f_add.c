/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** f_add.c
*/

#include "corewar.h"
#include <criterion/criterion.h>

champion_t *ini_champ(machine_t *machine);

Test(Corewar, adding)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 0;
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x01;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.champion[0]->process->instruct->arg[2][0] = 0x03;
    machine.champion[0]->process->registers[0] = 1;
    machine.champion[0]->process->registers[1] = 2;
    machine.champion[0]->process->registers[2] = 0x100;
    f_add(&machine, machine.champion[0]);
    cr_assert_eq(machine.champion[0]->process->registers[2], 3);
    cr_assert_eq(machine.champion[0]->process->pc, 5);
    cr_assert(!machine.champion[0]->process->carry);
}

Test(Corewar, adding_result_equal_0)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 0;
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x01;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.champion[0]->process->instruct->arg[2][0] = 0x03;
    machine.champion[0]->process->registers[0] = 0;
    machine.champion[0]->process->registers[1] = 0;
    machine.champion[0]->process->registers[2] = 0x100;
    f_add(&machine, machine.champion[0]);
    cr_assert_eq(machine.champion[0]->process->registers[2], 0);
    cr_assert_eq(machine.champion[0]->process->pc, 5);
    cr_assert(machine.champion[0]->process->carry);
}
