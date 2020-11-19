/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** f_sti.c
*/

#include "corewar.h"
#include <criterion/criterion.h>

champion_t *ini_champ(machine_t *machine);

Test(Asm, sti_direct)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 9;
    machine.champion[0]->process->registers[0] = 0x01;
    machine.champion[0]->process->registers[1] = 0x32;
    machine.champion[0]->process->instruct->code = 0x0b;
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b10;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x02;
    machine.champion[0]->process->instruct->arg[1][0] = 0x00;
    machine.champion[0]->process->instruct->arg[1][1] = 0x05;
    machine.champion[0]->process->instruct->arg[2][0] = 0x01;
    f_sti(&machine, machine.champion[0]);
    cr_expect_eq(machine.map[18], 0x32);
    cr_expect_eq(machine.champion[0]->process->pc, 15);
}

Test(Asm, sti_indirect)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 1;
    machine.champion[0]->process->instruct->code = 0x0b;
    machine.champion[0]->process->registers[0] = 0x15;
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b11;
    machine.champion[0]->process->instruct->mask[2] = 0b10;
    machine.champion[0]->process->instruct->arg[0][0] = 0x01;
    machine.champion[0]->process->instruct->arg[1][0] = 0xFF;
    machine.champion[0]->process->instruct->arg[1][1] = 0xFF;
    machine.champion[0]->process->instruct->arg[2][0] = 0x00;
    machine.champion[0]->process->instruct->arg[2][1] = 0x05;
    machine.map[1] = 0x06;
    f_sti(&machine, machine.champion[0]);
    cr_expect_eq(machine.map[15], 0x15);
    cr_expect_eq(machine.champion[0]->process->pc, 8);
}

Test(Asm, sti_register)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 1;
    machine.champion[0]->process->registers[0] = 0x15;
    machine.champion[0]->process->registers[1] = 0x03;
    machine.champion[0]->process->registers[2] = 0x09;
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x01;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.champion[0]->process->instruct->arg[2][0] = 0x03;
    f_sti(&machine, machine.champion[0]);
    cr_expect_eq(machine.map[16], 0x15);
    cr_expect_eq(machine.champion[0]->process->pc, 6);
}

Test(Asm, sti_register_idx_mod)
{
    machine_t machine;

    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 1;
    machine.champion[0]->process->registers[0] = 0x15;
    machine.champion[0]->process->registers[1] = 0x03 + IDX_MOD;
    machine.champion[0]->process->registers[2] = 0x09;
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x01;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.champion[0]->process->instruct->arg[2][0] = 0x03;
    f_sti(&machine, machine.champion[0]);
    cr_expect_eq(machine.map[16], 0x15);
    cr_expect_eq(machine.champion[0]->process->pc, 6);
}

Test(Asm, sti_example)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 1;
    machine.champion[0]->process->registers[0] = 0x32;
    machine.champion[0]->process->instruct->code = 0x0b;
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b10;
    machine.champion[0]->process->instruct->mask[2] = 0b10;
    machine.champion[0]->process->instruct->arg[0][0] = 0x01;
    machine.champion[0]->process->instruct->arg[1][0] = 0x00;
    machine.champion[0]->process->instruct->arg[1][1] = 0x23;
    machine.champion[0]->process->instruct->arg[2][0] = 0x00;
    machine.champion[0]->process->instruct->arg[2][1] = 0x01;
    f_sti(&machine, machine.champion[0]);
    cr_expect_eq(machine.map[0x28], 0x32);
    cr_expect_eq(machine.champion[0]->process->pc, 8);
}
