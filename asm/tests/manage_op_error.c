/*
** EPITECH PROJECT, 2019
** asm
** File description:
** test manage_op
*/

#include "asm.h"
#include <criterion/criterion.h>

bool is_right_label(line_t *line);

Test(Asm, wrong_instruct_number_arg, .init = redirect_all_std)
{
    line_t line;
    data_t data = ini_data();
    int prog_size = 0;
    char *arg[] = {"r1", NULL};

    line.nb_arg = 2;
    line.line = "live";
    data.line = &line;
    cr_assert(!is_instructs_correct(data, &prog_size));
    data.line->nb_arg = 1;
    data.line->args = arg;
    cr_assert(!is_instructs_correct(data, &prog_size));
}

Test(Asm, not_a_right_label)
{
    line_t line;

    line.line = "live";
    cr_assert(!is_right_label(&line));
}
