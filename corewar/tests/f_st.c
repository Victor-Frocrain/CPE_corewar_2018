/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** f_ld.c
*/

#include "corewar.h"
#include <criterion/criterion.h>

champion_t *ini_champ(machine_t *machine);

Test(Corewar, store_indirect)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->instruct->code = 0x03;
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b11;
    machine.champion[0]->process->instruct->arg[0][0] = 0x02;
    machine.champion[0]->process->instruct->arg[1][0] = 0x00;
    machine.champion[0]->process->instruct->arg[1][1] = 0x07;
    machine.champion[0]->process->pc = 1;
    machine.champion[0]->process->registers[1] = 0x08091011;
    f_st(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, 6);
    cr_expect_eq(machine.map[8], 0x08);
    cr_expect_eq(machine.map[9], 0x09);
    cr_expect_eq(machine.map[10], 0x10);
    cr_expect_eq(machine.map[11], 0x11);
}

Test(Corewar, store_indirect_idx_mod)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b11;
    machine.champion[0]->process->instruct->arg[0][0] = 0x02;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.champion[0]->process->instruct->arg[1][1] = 0x07;
    machine.champion[0]->process->pc = 1;
    machine.champion[0]->process->registers[1] = 0x10;
    f_st(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, 6);
    cr_expect_eq(machine.map[11], 0x10);
}

Test(Corewar, store_register)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x02;
    machine.champion[0]->process->instruct->arg[1][0] = 0x01;
    machine.champion[0]->process->pc = 0;
    machine.champion[0]->process->registers[0] = 0x48;
    machine.champion[0]->process->registers[1] = 0x10;
    f_st(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, 4);
    cr_expect_eq(machine.champion[0]->process->registers[0], 0x10);
}

Test(Corewar, store_indirect_backward)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b11;
    machine.champion[0]->process->instruct->arg[0][0] = 0x01;
    machine.champion[0]->process->instruct->arg[1][0] = 0xFF;
    machine.champion[0]->process->instruct->arg[1][1] = 0xFC;
    machine.champion[0]->process->pc = 0;
    machine.champion[0]->process->registers[0] = 0x10;
    f_st(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, 5);
    cr_expect_eq(machine.map[MEM_SIZE - 1], 0x10);
}
