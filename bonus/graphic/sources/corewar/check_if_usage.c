/*
** EPITECH PROJECT, 2019
** Corewar
** File description:
** check_if_usage.c
*/

#include "corewar.h"

void display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./corewar [-dump nbr_cycle] [[-n prog_number] \
[-a load_address] prog_name] ...\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\t-dump nbr_cycle\tdumps the memory after the \
nbr_cycle execution (if the round isn't\n");
    my_putstr("\t\t\talready over) with the following format: \
32 bytes/line in\n");
    my_putstr("\t\t\thexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("\t-n prog_number\tsets the next program's number. \
By default, the first free number\n");
    my_putstr("\t\t\tin the parameter order\n");
    my_putstr("\t-a load_address\tsets the next program's loading \
address. When no address is\n");
    my_putstr("\t\t\tspecified, optimize the addresses so that the \
processes are as far\n");
    my_putstr("\t\t\taway from each other as possible. The addresses \
are MEM_SIZE modulo\n");
}

bool check_if_usage(int ac, char **av)
{
    if (ac != 2)
        return (false);
    if (my_strcmp(av[1], "-h")) {
        display_usage();
        return (true);
    }
    return (false);
}
