/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** is_instruct_correct
*/

#include "corewar.h"

bool is_reg_outside(int nb)
{
    if (nb >= REG_NUMBER || nb < 0)
        return (true);
    return (false);
}

bool is_reg_correct(args_type_t type, const char *arg)
{
    if ((type & T_REG) == 0)
        return (false);
    return (!is_reg_outside(arg[0]));
}

bool is_instruct_correct(const instruct_t *instruct)
{
    int code = instruct->code;
    bool is_error = false;

    if (code < 1 || code > 16)
        return (false);
    if (instruct->nb_arg != op_tab[code - 1].nbr_args)
        return (false);
    for (int i = 0; !is_error && i < instruct->nb_arg; i++) {
        is_error = true;
        if (instruct->mask[i] == 0b01)
            is_error = !is_reg_correct(op_tab[code - 1].type[i], \
instruct->arg[i]);
        if (is_error && instruct->mask[i] == 0b10)
            is_error = (op_tab[code - 1].type[i] & T_DIR) == 0;
        if (is_error && instruct->mask[i] == 0b11)
            is_error = (op_tab[code - 1].type[i] & T_IND) == 0;
    }
    return (!is_error);
}
