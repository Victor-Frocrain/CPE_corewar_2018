/*
** EPITECH PROJECT, 2019
** asm
** File description:
** test arg type error
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

bool is_right_label(line_t *line);

Test(Asm, register_number_error)
{
    char *arg = "rtu";
    char *arg2 = "r360";
    bool is_error = false;
    bool is_error2 = false;
    int prog_size = 0;

    cr_assert(is_register(arg, &is_error, &prog_size));
    cr_assert(is_error);
    cr_assert(is_register(arg2, &is_error2, &prog_size));
    cr_assert(is_error2);
}

Test(Asm, indirect_number_error)
{
    char *arg = "tu";
    bool is_error = false;
    int prog_size = 0;
    line_t line;

    line.line = "and";
    cr_assert(!is_indirect(arg, &line, &is_error, &prog_size));
    cr_assert(is_error);
}

Test(Asm, undefined_label)
{
    char *arg = ":live";
    bool is_error = false;
    line_t line;

    line.line = "and";
    line.next = NULL;
    cr_assert(is_label(arg, &line, &is_error));
    cr_assert(is_error);
}

Test(Asm, direct_not_a_number)
{
    char *arg = "%tu";
    bool is_error = false;
    int prog_size = 0;

    cr_assert(is_direct(arg, NULL, &is_error, &prog_size));
    cr_assert(is_error);
}

Test(Asm, is_right_label, .init = redirect_all_std)
{
    line_t line;
    char *arg[] = {NULL};
    data_t data = ini_data();
    int prog_size = 0;

    line.nb_arg = 0;
    line.args = arg;
    line.nb_line = 1;
    line.line = "'-:";
    cr_assert(!is_instruct_correct(&line, data, &prog_size));
    cr_assert_stderr_eq_str("\033[1;35mLine 1: wrong label name, should only \
contain LABEL_CHARS\n");
    line.line = "live:";
    cr_assert(is_right_label(&line));
}
