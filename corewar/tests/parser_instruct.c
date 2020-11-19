/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** parser_instruct
*/

#include "corewar.h"
#include <criterion/criterion.h>

Test(Corewar, wrong_param_for_instruct)
{
    instruct_t *instruct = malloc(sizeof(instruct_t));

    instruct->code = 1;
    instruct->nb_arg = 1;
    instruct->mask[0] = REGISTER;
    instruct->arg[0][0] = 2;
    cr_assert(!is_instruct_correct(instruct));
    free(instruct);
}

Test(Corewar, wrong_register)
{
    instruct_t *instruct = malloc(sizeof(instruct_t));

    instruct->code = 3;
    instruct->nb_arg = 3;
    for (int i = 0; i < 3; i++) {
        instruct->mask[i] = REGISTER;
        instruct->arg[i][0] = 0;
    }
    cr_assert(!is_instruct_correct(instruct));
    free(instruct);
}
