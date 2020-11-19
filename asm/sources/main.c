/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "asm.h"
#include <stdio.h>

void display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./asm file_name[.s]\n");
    my_putchar('\n');
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfile_name\tfile in assembly language to be converted into \
file_name.cor, an\n");
    my_putstr("\t\t\texecutable in the Virtual Machine.\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h")) {
        display_usage();
        return (MY_SUCCESS);
    }
    if (is_arguments_error(ac, av))
        return (MY_ERROR);
    return (read_files(ac, av));
}
