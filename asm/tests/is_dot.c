/*
** EPITECH PROJECT, 2019
** asm
** File description:
** is_dot.c
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

bool is_dot_name(line_t *line);
bool is_dot_comment(line_t *line, bool *is_error);

Test(Asm, dot_name_argument_error, .init = redirect_all_std)
{
    line_t not_enough;
    line_t too_much;

    not_enough.line = ".name";
    not_enough.nb_arg = 0;
    not_enough.nb_line = 1;
    too_much.line = ".name";
    too_much.nb_arg = 2;
    too_much.nb_line = 1;
    cr_assert(!is_dot_name(&not_enough));
    cr_assert(!is_dot_name(&too_much));
}

Test(Asm, multiple_dot_name, .init = redirect_all_std)
{
    line_t *line = malloc(sizeof(line_t));
    line_t *next = malloc(sizeof(line_t));

    line->line = ".name";
    line->nb_arg = 1;
    next->line = ".name";
    line->next = next;
    line->nb_line = 1;
    next->nb_line = 2;
    cr_assert(!is_dot_name(line));
    cr_assert_stderr_eq_str("\033[1;35mLine 2: multiple declaration \
of .name\n");
}

Test(Asm, dot_comment_argument_error, .init = redirect_all_std)
{
    line_t not_enough;
    line_t too_much;
    bool is_error = false;

    not_enough.line = ".comment";
    not_enough.nb_arg = 0;
    not_enough.nb_line = 1;
    too_much.line = ".comment";
    too_much.nb_arg = 2;
    too_much.nb_line = 1;
    cr_assert(!is_dot_comment(&not_enough, &is_error));
    cr_assert(!is_dot_comment(&too_much, &is_error));
}

Test(Asm, multiple_comment_name, .init = redirect_all_std)
{
    line_t *line = malloc(sizeof(line_t));
    line_t *next = malloc(sizeof(line_t));
    bool is_error = false;

    line->line = ".comment";
    line->nb_arg = 1;
    next->line = ".comment";
    line->next = next;
    line->nb_line = 1;
    next->nb_line = 2;
    cr_assert(!is_dot_comment(line, &is_error));
    cr_assert_stderr_eq_str("\033[1;35mLine 2: multiple declaration \
of .comment\n");
}
