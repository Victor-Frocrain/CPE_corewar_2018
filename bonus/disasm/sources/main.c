/*
** EPITECH PROJECT, 2019
** disasm
** File description:
** main.c
*/

#include "disasm.h"

void display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./disasm file_name[.cor]\n");
    my_putchar('\n');
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfile_name\tfile in bytecode to be converted to\n");
    my_putstr("\t\t\tfile_name.s, in assembly language.\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h")) {
        display_usage();
        return (MY_SUCCESS);
    }
    if (parser(ac, av))
        return (MY_ERROR);
    return (disasm(ac, av));
}
