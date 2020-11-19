/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** f_live.c
*/

#include "corewar.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

champion_t *ini_champ(machine_t *machine)
{
    champion_t *champion = malloc(sizeof(champion_t));
    header_t *header = malloc(sizeof(header_t));
    process_t *process = malloc(sizeof(process_t));
    instruct_t *instruct = malloc(sizeof(instruct_t));

    strcpy(header->prog_name, "zork");
    champion->header = header;
    machine->total++;
    champion->is_alive = false;
    champion->was_living = false;
    champion->process = process;
    process->instruct = instruct;
    champion->process->pc = 0;
    champion->process->carry = false;
    champion->process->next = NULL;
    champion->process->cumu_cycle = 0;
    champion->number = 1;
    for (int i = 0; i < REG_NUMBER; i++)
        champion->process->registers[i] = 0;
    return (champion);
}

Test(Corewar, saying_live, .init = redirect_all_std)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[0]->process->instruct->arg[0][0] = 0;
    machine.champion[0]->process->pc = 1;
    machine.champion[0]->was_living = true;
    machine.champion[0]->process->instruct->arg[0][1] = 0;
    machine.champion[0]->process->instruct->arg[0][2] = 0;
    machine.champion[0]->process->instruct->arg[0][3] = 1;
    machine.total = 1;
    machine.champion[0]->number = 1;
    f_live(&machine, machine.champion[0]);
    cr_expect(machine.champion[0]->is_alive);
    cr_expect_eq(machine.champion[0]->process->cumu_cycle, 0);
    cr_expect_eq(machine.champion[0]->process->pc, 6);
    cr_expect_stdout_eq_str("The player 1(zork) is alive\n");
}

Test(Corewar, saying_live_for_another_champ, .init = redirect_all_std)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[1] = ini_champ(&machine);
    machine.champion[0]->process->instruct->arg[0][0] = 0;
    machine.champion[0]->process->instruct->arg[0][1] = 0;
    machine.champion[0]->process->instruct->arg[0][2] = 0;
    machine.champion[0]->process->instruct->arg[0][3] = 2;
    machine.champion[0]->process->pc = MEM_SIZE - 1;
    machine.champion[0]->number = 1;
    machine.champion[1]->number = 2;
    machine.champion[0]->was_living = true;
    machine.champion[1]->was_living = true;
    machine.total = 2;
    f_live(&machine, machine.champion[0]);
    cr_expect(!machine.champion[0]->is_alive);
    cr_expect(machine.champion[1]->is_alive);
    cr_expect_eq(machine.champion[0]->process->pc, 4);
    cr_assert_stdout_eq_str("The player 2(zork) is alive\n");
}

Test(Corewar, saying_live_for_dead_champ)
{
    machine_t machine;

    memset(machine.map, 0, MEM_SIZE);
    machine.champion[0] = ini_champ(&machine);
    machine.champion[1] = ini_champ(&machine);
    machine.champion[0]->process->instruct->arg[0][0] = 0;
    machine.champion[0]->process->instruct->arg[0][1] = 0;
    machine.champion[0]->process->instruct->arg[0][2] = 0;
    machine.champion[0]->process->instruct->arg[0][3] = 2;
    machine.champion[0]->process->pc = MEM_SIZE - 1;
    machine.champion[0]->number = 1;
    machine.champion[1]->number = 2;
    machine.champion[0]->was_living = true;
    machine.champion[1]->was_living = false;
    machine.total = 2;
    f_live(&machine, machine.champion[0]);
    cr_expect(!machine.champion[0]->is_alive);
    cr_expect(!machine.champion[1]->is_alive);
    cr_expect_eq(machine.champion[0]->process->pc, 4);
}
