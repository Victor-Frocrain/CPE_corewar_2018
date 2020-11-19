/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** filling_instruct
*/

#include "corewar.h"
#include <criterion/criterion.h>

instruct_t *ini_and_fill_instruct(int code, int nb_arg)
{
    instruct_t *instruct = malloc(sizeof(instruct_t));

    instruct->code = code;
    instruct->nb_arg = nb_arg;
    for (int i = 0; i < 3; i++) {
        instruct->mask[i] = 0;
        memset(instruct->arg[i], 0, 5);
    }
    return (instruct);
}

Test(Corewar, fill_live_instruct)
{
    machine_t machine;
    instruct_t *instruct = ini_and_fill_instruct(0x00, 0);

    memset(machine.map, 0, MEM_SIZE);
    machine.map[0] = 0x01;
    machine.map[1] = 0x00;
    machine.map[2] = 0x00;
    machine.map[3] = 0x00;
    machine.map[4] = 0x2a;
    fill_instruct(instruct, machine, 0);
    cr_expect_eq(instruct->code, 0x01);
    cr_expect_eq(instruct->nb_arg, 1);
    for (int i = 0; i < 3; i++)
        cr_expect_eq(instruct->arg[0][i], 0x00);
    cr_expect_eq(instruct->arg[0][3], 0x2a);
}

Test(Corewar, fill_ld_instruct)
{
    machine_t machine;
    instruct_t *instruct = ini_and_fill_instruct(0x00, 0);

    memset(machine.map, 0, MEM_SIZE);
    machine.map[0] = 0x02;
    machine.map[1] = 0x90;
    machine.map[5] = 0x04;
    machine.map[6] = 0x01;
    fill_instruct(instruct, machine, 0);
    cr_expect_eq(instruct->code, 0x02);
    cr_expect_eq(instruct->nb_arg, 2);
    for (int i = 0; i < 3; i++)
        cr_expect_eq(instruct->arg[0][i], 0x00);
    cr_expect_eq(instruct->arg[0][3], 0x04);
    cr_expect_eq(instruct->arg[1][0], 0x01);
}

Test(Corewar, fill_ldi_instruct)
{
    machine_t machine;
    instruct_t *instruct = ini_and_fill_instruct(0x00, 0);

    memset(machine.map, 0, MEM_SIZE);
    machine.map[0] = 0x0a;
    machine.map[1] = 0xe4;
    machine.map[3] = 0x03;
    machine.map[5] = 0x04;
    machine.map[6] = 0x01;
    fill_instruct(instruct, machine, 0);
    cr_expect_eq(instruct->code, 0x0a);
    cr_expect_eq(instruct->nb_arg, 3);
    for (int i = 0; i < 2; i++)
        cr_expect_eq(instruct->arg[1][0], 0x00);
    cr_expect_eq(instruct->arg[0][1], 0x03);
    cr_expect_eq(instruct->arg[1][1], 0x04);
    cr_expect_eq(instruct->arg[2][0], 0x01);
}

Test(Corewar, fill_wrong_instruct)
{
    machine_t machine;
    instruct_t *instruct = ini_and_fill_instruct(0x00, 0);

    memset(machine.map, 0, MEM_SIZE);
    machine.map[0] = 0x0a;
    machine.map[1] = 0xFF;
    machine.map[3] = 0x03;
    machine.map[5] = 0x04;
    machine.map[6] = 0x01;
    fill_instruct(instruct, machine, 0);
    cr_assert(!is_instruct_correct(instruct));
}
