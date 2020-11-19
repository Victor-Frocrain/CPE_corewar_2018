/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** f_xor
*/

#include "corewar.h"
#include <criterion/criterion.h>

champion_t *ini_champ(machine_t *champion);

Test(Corewar, xor_with_reg)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 0;
    machine.champion[0]->process->registers[0] = 0b101;
    machine.champion[0]->process->registers[1] = 0b111;
    machine.champion[0]->process->registers[2] = 0b010;
    machine.champion[0]->process->instruct->mask[0] = 0b01;
    machine.champion[0]->process->instruct->mask[1] = 0b01;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x01;
    machine.champion[0]->process->instruct->arg[1][0] = 0x02;
    machine.champion[0]->process->instruct->arg[2][0] = 0x03;
    f_xor(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[2], 0b010);
    cr_expect(!machine.champion[0]->process->carry);
    cr_expect_eq(machine.champion[0]->process->pc, 5);
}

Test(Corewar, xor_with_dir)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 1;
    machine.champion[0]->process->registers[0] = 1;
    machine.champion[0]->process->instruct->mask[0] = 0b10;
    machine.champion[0]->process->instruct->mask[1] = 0b10;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            machine.champion[0]->process->instruct->arg[j][i] = 0x00;
    machine.champion[0]->process->instruct->arg[0][3] = 0b011;
    machine.champion[0]->process->instruct->arg[1][3] = 0b010;
    machine.champion[0]->process->instruct->arg[2][0] = 0x02;
    f_xor(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[1], 0b001);
    cr_expect(!machine.champion[0]->process->carry);
    cr_expect_eq(machine.champion[0]->process->pc, 12);
}

Test(Corewar, xor_with_indir)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 0;
    machine.champion[0]->process->registers[0] = 1;
    machine.champion[0]->process->registers[1] = 5;
    machine.champion[0]->process->instruct->mask[0] = 0b11;
    machine.champion[0]->process->instruct->mask[1] = 0b11;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    machine.champion[0]->process->instruct->arg[0][0] = 0x00;
    machine.champion[0]->process->instruct->arg[0][1] = 0x02;
    machine.champion[0]->process->instruct->arg[1][0] = 0x00;
    machine.champion[0]->process->instruct->arg[1][1] = 0x04;
    machine.champion[0]->process->instruct->arg[2][0] = 0x02;
    machine.map[3] = 0b101;
    machine.map[5] = 0b100;
    f_xor(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[1], 0b001);
    cr_expect_eq(machine.champion[0]->process->pc, 7);
    cr_expect(!machine.champion[0]->process->carry);
}

Test(Corewar, xor_result_equal_0)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 1;
    machine.champion[0]->process->registers[0] = 1;
    machine.champion[0]->process->instruct->mask[0] = 0b10;
    machine.champion[0]->process->instruct->mask[1] = 0b10;
    machine.champion[0]->process->instruct->mask[2] = 0b01;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            machine.champion[0]->process->instruct->arg[j][i] = 0x11;
    machine.champion[0]->process->instruct->arg[2][0] = 0x02;
    f_xor(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->registers[1], 0b000);
    cr_expect(machine.champion[0]->process->carry);
    cr_expect_eq(machine.champion[0]->process->pc, 12);
}
