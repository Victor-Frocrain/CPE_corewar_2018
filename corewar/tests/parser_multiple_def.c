/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** testing_parser_multiple_definition
*/

#include "corewar.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Corewar, multiple_definition_of_address, .init = redirect_all_std)
{
    char *arg[8] = {"./corewar", "-a", "4", "-a", "4", "zork.cor", \
"zork.cor", NULL};

    cr_assert_eq(corewar(7, arg), MY_ERROR);
    cr_assert_stderr_eq_str("\033[1;35mError: multiple declaration of -a in \
zork.cor\n\033[0;m");
}

Test(Corewar, address_outside_the_bound, .init = redirect_all_std)
{
    char *arg[6] = {"./corewar", "-a", "999999999", "zork.cor", \
"zork.cor", NULL};

    cr_assert_eq(corewar(5, arg), MY_ERROR);
    cr_assert_stderr_eq_str("\033[1;35mError: the specified address is outside \
the memory bounds.\n\033[0;m");
}

Test(Corewar, multiple_definition_of_dump, .init = redirect_all_std)
{
    char *arg[8] = {"./corewar", "-dump", "4", "zork.cor", "zork.cor", \
"-dump", "4", NULL};

    cr_assert_eq(corewar(7, arg), MY_ERROR);
    cr_assert_stderr_eq_str("\033[1;35mError: multiple declaration of \
-dump\n\033[0;m");
}

Test(Corewar, multiple_definition_of_number, .init = redirect_all_std)
{
    char *arg[8] = {"./corewar", "-n", "4", "-n", "4", "zork.cor", \
"zork.cor", NULL};

    cr_assert_eq(corewar(7, arg), MY_ERROR);
    cr_assert_stderr_eq_str("\033[1;35mError: multiple declaration of \
-n in zork.cor\n\033[0;m");
}
