/*
** EPITECH PROJECT, 2019
** identify_flags
** File description:
** identify_flags
*/

#include "corewar.h"

bool manage_address(char *arg, champion_t *champion, char *cor_name)
{
    int address = my_getnbr(arg);

    if (champion->process->pc >= 0){
        print_error_color(C_MAGENTA, "Error: multiple declaration \
of -a in ");
        my_puterror(cor_name);
        my_puterror("\n");
        return (true);
    }
    if (address < MEM_SIZE && address >= 0) {
        champion->process->pc = address;
        return (false);
    }
    print_error_color(C_MAGENTA, "Error: the specified address is \
outside the memory bounds.\n");
    return (true);
}

bool fill_dump(char **av, int old_core, machine_t *machine)
{
    if ((*machine).dump >= 0) {
        print_error_color(C_MAGENTA, "Error: multiple declaration \
of -dump\n");
        return (true);
    }
    (*machine).dump = my_getnbr(av[old_core + 1]);
    return (false);
}

bool is_number_used(champion_t **champion, int total)
{
    bool is_error = false;

    for (int i = 0; !is_error && i < total; i++)
        for (int j = 0; !is_error && j < total; j++)
            is_error = champion[i] != champion[j] && \
champion[i]->number == champion[j]->number;
    if (is_error)
        print_error_color(C_MAGENTA, "Error: multiple champion have the same \
number\n");
    return (is_error);
}

bool fill_flags(char **av, champion_t *champion, int old_core, int new_core)
{
    if (my_strcmp(av[old_core], "-a"))
        return (manage_address(av[old_core + 1], champion, av[new_core]));
    if (my_strcmp(av[old_core], "-n")) {
        if (champion->number >= 0) {
            print_error_color(C_MAGENTA, "Error: multiple declaration \
of -n in ");
            my_puterror(av[new_core]);
            my_puterror("\n");
            return (true);
        }
        champion->number = my_getnbr(av[old_core + 1]);
    }
    return (false);
}

bool identify_flags(char **av, machine_t *machine, int old_core, int new_core)
{
    bool is_flag = my_strcmp(av[old_core], "-dump") || my_strcmp(av[old_core], \
"-n") || my_strcmp(av[old_core], "-a");

    if (!is_flag) {
        print_error_color(C_MAGENTA, "Error: bad parameter\n");
        return (true);
    }
    if (old_core + 1 >= new_core) {
        print_error_color(C_MAGENTA, "Error: argument needed for ");
        my_puterror(av[old_core]);
        my_puterror("\n");
        return (true);
    }
    if (!check_value(av[old_core + 1]))
        return (true);
    if (my_strcmp(av[old_core], "-dump"))
        return (fill_dump(av, old_core, machine));
    return (fill_flags(av, (*machine).champion[(*machine).total - 1], \
old_core, new_core));
}
