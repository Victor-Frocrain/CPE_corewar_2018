/*
** EPITECH PROJECT, 2019
** asm
** File description:
** read_line.c
*/

#include "asm.h"
#include <criterion/criterion.h>

void fill_line_after_label(line_t *line, bool *is_error);

Test(Asm, fill_line_after_label)
{
    line_t *line = malloc(sizeof(line_t));
    char *arg[] = {"add", "r1", "r2", "r3", NULL};
    bool is_error = false;

    line->line = "l2:";
    line->args = arg;
    line->nb_arg = 4;
    line->nb_line = 2;
    line->next = NULL;
    fill_line_after_label(line, &is_error);
    cr_assert(!is_error);
    cr_assert(line->next);
    cr_assert_str_eq("add", line->next->line);
    cr_assert_str_eq("r1", line->next->args[0]);
    cr_assert_str_eq("r2", line->next->args[1]);
    cr_assert_str_eq("r3", line->next->args[2]);
}
