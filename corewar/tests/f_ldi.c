/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** ldi.c
*/

#include "corewar.h"
#include <criterion/criterion.h>

champion_t *ini_champ(machine_t *machine);

Test(Asm, ldi_direct)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 9;
    machine.champion[0]->process->registers[0] = 9;
    machine.champion[0]->process->instruct->code = 0x0a;
    machine.champion[0]->process->instruct->mask[0] = 0b10;
    machine.champion[0]->process->instruct->mask[1] = 0b10;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x00;
    machine.champion[0]->process->instruct->arg[0][1] = 0x05;
    machine.champion[0]->process->instruct->arg[1][0] = 0x00;
    machine.champion[0]->process->instruct->arg[1][1] = 0x04;
    machine.champion[0]->process->instruct->arg[2][0] = 0x02;
    machine.map[21] = 0x32;
    f_ldi(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[1], 0x32);
    cr_expect_eq(machine.champion[0]->process->pc, 16);
    cr_expect(!machine.champion[0]->process->carry);
}

Test(Asm, ldi_indirect)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 1;
    machine.champion[0]->process->instruct->code = 0x0a;
    machine.champion[0]->process->registers[0] = 9;
    machine.champion[0]->process->instruct->mask[0] = 0b11;
    machine.champion[0]->process->instruct->mask[1] = 0b10;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0xFF;
    machine.champion[0]->process->instruct->arg[0][1] = 0xFF;
    machine.champion[0]->process->instruct->arg[1][0] = 0x00;
    machine.champion[0]->process->instruct->arg[1][1] = 0x05;
    machine.champion[0]->process->instruct->arg[2][0] = 0x01;
    machine.map[1] = 0x05;
    machine.map[14] = 0x15;
    f_ldi(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[0], 0x15);
    cr_expect_eq(machine.champion[0]->process->pc, 8);
    cr_expect(!machine.champion[0]->process->carry);
}

Test(Asm, ldi_register)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 1;
    machine.champion[0]->process->registers[0] = 0x02;
    machine.champion[0]->process->registers[1] = 0x03;
    machine.champion[0]->process->registers[2] = 0x09;
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x01;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.champion[0]->process->instruct->arg[2][0] = 0x03;
    machine.map[9] = 0x15;
    f_ldi(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[2], 0x15);
    cr_expect_eq(machine.champion[0]->process->pc, 6);
    cr_expect(!machine.champion[0]->process->carry);
}

Test(Asm, ldi_register_idx_mod)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 1;
    machine.champion[0]->process->registers[0] = 0x02;
    machine.champion[0]->process->registers[1] = 0x03 + IDX_MOD;
    machine.champion[0]->process->registers[2] = 0x09;
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x01;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.champion[0]->process->instruct->arg[2][0] = 0x03;
    machine.map[9] = 0x15;
    f_ldi(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[2], 0x15);
    cr_expect_eq(machine.champion[0]->process->pc, 6);
    cr_expect(!machine.champion[0]->process->carry);
}

Test(Asm, ldi_sum_equal_0)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 6;
    machine.champion[0]->process->registers[0] = 0x00;
    machine.champion[0]->process->registers[1] = 0x00;
    machine.champion[0]->process->registers[2] = 0xFF;
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x01;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.champion[0]->process->instruct->arg[2][0] = 0x03;
    f_ldi(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[2], 0x00);
    cr_expect_eq(machine.champion[0]->process->pc, 11);
    cr_expect(machine.champion[0]->process->carry);
}
