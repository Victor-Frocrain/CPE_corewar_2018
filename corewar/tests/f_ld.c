/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** f_ld.c
*/

#include "corewar.h"
#include <criterion/criterion.h>

champion_t *ini_champ(machine_t *machine);

Test(Corewar, load_direct)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->instruct->mask[0] = 0b10;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x00;
    machine.champion[0]->process->instruct->arg[0][1] = 0x00;
    machine.champion[0]->process->instruct->arg[0][2] = 0x00;
    machine.champion[0]->process->instruct->arg[0][3] = 0x0a;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.champion[0]->process->pc = 4;
    f_ld(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[1], 0x0a);
    cr_expect_eq(machine.champion[0]->process->pc, 11);
    cr_expect(!machine.champion[0]->process->carry);
}

Test(Corewar, load_indirect_beyound)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->instruct->mask[0] = 0b11;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0xFF;
    machine.champion[0]->process->instruct->arg[0][1] = 0xFB;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.champion[0]->process->pc = 4;
    machine.map[2] = 0x12;
    f_ld(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[1], 0x12);
    cr_expect_eq(machine.champion[0]->process->pc, 9);
    cr_expect(!machine.champion[0]->process->carry);
}

Test(Corewar, load_indirect)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->instruct->mask[0] = 0b11;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x00;
    machine.champion[0]->process->instruct->arg[0][1] = 0x07;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.map[10] = 0x02;
    machine.champion[0]->process->pc = 0;
    f_ld(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[1], 2);
    cr_expect_eq(machine.champion[0]->process->pc, 5);
    cr_expect(!machine.champion[0]->process->carry);
}

Test(Corewar, load_indirect_idx_mod)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->instruct->mask[0] = 0b11;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x02;
    machine.champion[0]->process->instruct->arg[0][1] = 0x0a;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.map[13] = 0x02;
    machine.champion[0]->process->pc = 0;
    f_ld(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[1], 2);
    cr_expect_eq(machine.champion[0]->process->pc, 5);
    cr_expect(!machine.champion[0]->process->carry);
}

Test(Corewar, load_value_equal_0)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->instruct->mask[0] = 0b10;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x00;
    machine.champion[0]->process->instruct->arg[0][1] = 0x00;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.map[10] = 0x02;
    machine.champion[0]->process->pc = 0;
    f_ld(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[1], 0);
    cr_expect_eq(machine.champion[0]->process->pc, 7);
    cr_expect(machine.champion[0]->process->carry);
}
