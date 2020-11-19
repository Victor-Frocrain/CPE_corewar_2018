/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** f_zjmp
*/

#include "corewar.h"
#include <criterion/criterion.h>

champion_t *ini_champ(machine_t *champion);

Test(Corewar, zjmp_dir)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 0;
    machine.champion[0]->process->carry = true;
    machine.champion[0]->process->instruct->arg[0][0] = 0x00;
    machine.champion[0]->process->instruct->arg[0][1] = 0x06;
    f_zjmp(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, 6);
}

Test(Corewar, zjmp_dir_idx_mod)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 0;
    machine.champion[0]->process->carry = true;
    machine.champion[0]->process->instruct->arg[0][0] = 0x02;
    machine.champion[0]->process->instruct->arg[0][1] = 0x06;
    f_zjmp(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, 6);
    machine.champion[0]->process->carry = false;
    f_zjmp(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, 9);
}

Test(Corewar, zjmp_go_back)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 1;
    machine.champion[0]->process->carry = true;
    machine.champion[0]->process->instruct->arg[0][0] = 0xFF;
    machine.champion[0]->process->instruct->arg[0][1] = 0xFF;
    f_zjmp(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, 0);
}

Test(Corewar, zjmp_go_back_mem_circle)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->carry = true;
    machine.champion[0]->process->pc = 2;
    machine.champion[0]->process->instruct->arg[0][0] = 0xFF;
    machine.champion[0]->process->instruct->arg[0][1] = 0xFA;
    f_zjmp(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, MEM_SIZE - 4);
}

Test(Corewar, zjmp_dont_move)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->carry = true;
    machine.champion[0]->process->pc = 6;
    machine.champion[0]->process->instruct->arg[0][0] = 0x00;
    machine.champion[0]->process->instruct->arg[0][1] = 0x00;
    f_zjmp(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, 6);
}
