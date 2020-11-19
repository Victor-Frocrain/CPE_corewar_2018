/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** testing_parser_value.c
*/

#include "corewar.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Corewar, wrong_type_of_value, .init = redirect_all_std)
{
    char *arg[6] = {"./corewar", "-a", "-12", "zork.cor", "zork.cor", NULL};

    cr_assert_eq(corewar(5, arg), MY_ERROR);
    cr_assert_stderr_eq_str("\033[1;35mError: the argument must be a positive \
number\n\033[0;m");
}

Test(Corewar, wrong_type_of_value_dump, .init = redirect_all_std)
{
    char *arg[6] = {"./corewar", "-dump", "-12", "zork.cor", "zork.cor", NULL};

    cr_assert_eq(corewar(5, arg), MY_ERROR);
    cr_assert_stderr_eq_str("\033[1;35mError: the argument must be a positive \
number\n\033[0;m");
}

Test(Corewar, param_without_champ, .init = redirect_all_std)
{
    char *arg[8] = {"./corewar", "-a", "12", "zork.cor", \
"zork.cor", "-a", "4", NULL};

    cr_assert_eq(corewar(5, arg), MY_ERROR);
    cr_assert_stderr_eq_str("\033[1;35mError: parameter without \
champion\n\033[0;m");
}

Test(Corewar, flag_without_value, .init = redirect_all_std)
{
    char *arg[8] = {"./corewar", "-a", "zork.cor", "zork.cor", NULL};

    cr_assert_eq(corewar(4, arg), MY_ERROR);
    cr_assert_stderr_eq_str("\033[1;35mError: argument needed for \
-a\n\033[0;m");
}
