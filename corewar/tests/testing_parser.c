/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** testing parser
*/

#include "corewar.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

machine_t init_machine(void);

Test(Corewar, fill_champion_number, .init = redirect_all_std)
{
    char *av[8] = {"./corewar", "-n", "4", "zork.cor", "-n", "4", \
"zork.cor", NULL};

    cr_expect_eq(corewar(8, av), MY_ERROR);
    cr_assert_stderr_eq_str("\033[1;35mError: multiple champion have the same \
number\n\033[0;m");
}

Test(Corewar, fill_champion_address)
{
    char *av[8] = {"./corewar", "-a", "4", "zork.cor", "-a", "5", \
"zork.cor", NULL};
    machine_t machine = init_machine();

    cr_expect(!parser(av, &machine));
    cr_expect_eq(machine.total, 2);
    cr_expect_eq(machine.champion[0]->process->pc, 4);
    cr_expect_eq(machine.champion[1]->process->pc, 5);
    cr_expect_str_eq(machine.champion[0]->header->prog_name, "zork");
    cr_expect_str_eq(machine.champion[1]->header->prog_name, "zork");
}

Test(Corewar, superimposed_champion, .init = redirect_all_std)
{
    char *av[8] = {"./corewar", "-a", "4", "zork.cor", "-a", "5", \
"zork.cor", NULL};

    cr_assert_eq(corewar(8, av), MY_ERROR);
    cr_assert_stderr_eq_str("\033[1;35mError: \033[1;34mzork\033[1;35m and \
\033[1;34mzork\033[1;35m are superimposed\n\033[0;m");
}

Test(Corewar, wrong_number_of_champ, .init = redirect_all_std)
{
    char *too_much[8] = {"./corewar", "zork.cor", "zork.cor", "zork.cor", \
"zork.cor", "zork.cor", NULL};

    cr_assert_eq(corewar(8, too_much), MY_ERROR);
    cr_assert_stderr_eq_str("\033[1;35mError: too much champions\n\033[0;m");
}

Test(Core, not_enough_champ, .init = redirect_all_std)
{
    char *not_enough[8] = {"./corewar", "zork.cor", NULL};

    cr_assert_eq(corewar(8, not_enough), MY_ERROR);
    cr_assert_stderr_eq_str("\033[1;35mError: not enough champions\n\033[0;m");
}
