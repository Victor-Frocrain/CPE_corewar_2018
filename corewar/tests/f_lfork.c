/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** f_lfork
*/

#include "corewar.h"
#include <criterion/criterion.h>

champion_t *ini_champ(machine_t *machine);

Test(Corewar, create_long_process)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 0;
    machine.champion[0]->process->instruct->code = 0x0c;
    machine.champion[0]->process->instruct->arg[0][0] = 0x00;
    machine.champion[0]->process->instruct->arg[0][1] = 0x01;
    f_lfork(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, 3);
    cr_assert(machine.champion[0]->process->next);
    cr_expect_eq(machine.champion[0]->process->next->pc, 1);
}

Test(Corewar, create_long_process_backward)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 5;
    machine.champion[0]->process->instruct->arg[0][0] = 0xFF;
    machine.champion[0]->process->instruct->arg[0][1] = 0xFF;
    f_lfork(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, 8);
    cr_assert(machine.champion[0]->process->next);
    cr_expect_eq(machine.champion[0]->process->next->pc, 4);
}

Test(Corewar, create_long_process_backward_mem_circle)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 0;
    machine.champion[0]->process->instruct->arg[0][0] = 0xFF;
    machine.champion[0]->process->instruct->arg[0][1] = 0xFF;
    f_lfork(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, 3);
    cr_assert(machine.champion[0]->process->next);
    cr_expect_eq(machine.champion[0]->process->next->pc, MEM_SIZE - 1);
}

Test(Corewar, create_long_process_with_pc_idx_mod)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->pc = 5;
    machine.champion[0]->process->instruct->arg[0][0] = 0x02;
    machine.champion[0]->process->instruct->arg[0][1] = 0x00;
    f_lfork(&machine, machine.champion[0]);
    cr_expect_eq(machine.champion[0]->process->pc, 8);
    cr_assert(machine.champion[0]->process->next);
    cr_expect_eq(machine.champion[0]->process->next->pc, 0x205);
}
