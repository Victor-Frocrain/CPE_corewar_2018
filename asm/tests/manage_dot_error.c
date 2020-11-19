/*
** EPITECH PROJECT, 2019
** asm
** File description:
** test manage dot errpr
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

bool is_dot_name(line_t *line);
bool is_dot_comment(line_t *line, bool *is_error);

Test(Asm, Multiple_definition_of_name, .init = redirect_all_std)
{
    line_t line;

    line.next = malloc(sizeof(line_t));
    line.next->nb_line = 2;
    line.line = ".name";
    line.next->line = ".name";
    line.nb_arg = 1;
    cr_assert(!is_dot_name(&line));
    cr_expect_stderr_eq_str("\033[1;35mLine 2: multiple \
declaration of .name\n");
    free(line.next);
}

Test(Asm, Multiple_definition_of_comment, .init = redirect_all_std)
{
    line_t line;
    bool is_error = false;

    line.next = malloc(sizeof(line_t));
    line.next->nb_line = 2;
    line.line = ".comment";
    line.next->line = ".comment";
    line.nb_arg = 1;
    cr_assert(!is_dot_comment(&line, &is_error));
    cr_assert(is_error);
    cr_expect_stderr_eq_str("\033[1;35mLine 2: multiple \
declaration of .comment\n");
    free(line.next);
}

Test(Asm, dot_undefined, .init = redirect_all_std)
{
    line_t line;
    line_t comment;
    bool is_error = false;

    comment.line = "live:";
    line.line = ".comment";
    line.nb_line = 1;
    cr_assert(!is_dot_name(&line));
    cr_assert_stderr_eq_str("\033[1;35mLine 1: .name is undefined or \
misplaced\n");
    cr_assert(!is_dot_comment(&comment, &is_error));
    cr_assert(!is_error);
}

Test(Asm, test_outside_quotes, .init = redirect_all_std)
{
    char *str = NULL;
    line_t line;
    char *arg[] = {"fezfz\"just a basic living prog\"", NULL};

    line.args = arg;
    line.nb_line = 1;
    cr_assert(manage_dot(&line, str, 2));
    cr_assert_stderr_eq_str("\033[1;35mLine 1: there is text outside quotes\n");
}
