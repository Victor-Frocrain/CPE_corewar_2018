/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** functional.c
*/

#include "corewar.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Corewar, functional, .init = redirect_all_std)
{
    int ac = 3;
    char *av[3] = {"./corewar", "bandol.cor", "bandol.cor"};

    cr_assert_eq(corewar(ac, av), MY_SUCCESS);
}

Test(Corewar, argument_error, .init = redirect_all_std)
{
    int ac = 3;
    char *av[3] = {"./corewar", "zork.s", "zork.cor"};

    cr_assert_eq(corewar(ac, av), MY_ERROR);
}

Test(Corewar, dumping, .init = redirect_all_std)
{
    int ac = 5;
    char *av[5] = {"./corewar", "zork.cor", "zork.cor", "-dump", "4"};

    cr_assert_eq(corewar(ac, av), MY_SUCCESS);
}

Test(Corewar, usage, .init = redirect_all_std)
{
    int ac = 2;
    char *av[3] = {"./corewar", "-h"};

    cr_assert_eq(corewar(ac, av), MY_SUCCESS);
    cr_assert_stdout_eq_str("USAGE\n\t./corewar [-dump nbr_cycle] \
[[-n prog_number] [-a load_address] prog_name] ...\n\nDESCRIPTION\n\t\
-dump nbr_cycle\tdumps the memory after the nbr_cycle execution (if the \
round isn't\n\t\t\talready over) with the following format: 32 bytes/line \
in\n\t\t\thexadecimal (A0BCDEFE1DD3...)\n\t-n prog_number\tsets the next \
program's number. By default, the first free number\n\t\t\tin the parameter \
order\n\t-a load_address\tsets the next program's loading address. When no \
address is\n\t\t\tspecified, optimize the addresses so that the processes are \
as far\n\t\t\taway from each other as possible. The addresses are MEM_SIZE \
modulo\n");
}
