/*
** EPITECH PROJECT, 2019
** Corewar
** File description:
** parser.c
*/

#include "corewar.h"

bool check_value(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9') {
            print_error_color(C_MAGENTA, "Error: the argument must be a \
positive number\n");
            return (false);
        }
    return (true);
}

bool is_file_core(char *str)
{
    int i = my_strlen(str) - 1;

    for (; i >= 0 && str[i] != '.'; i--);
    return (my_strcmp(str + i, ".cor"));
}

bool print_error_nb_champ(int nb)
{
    if (nb < 2)
        print_error_color(C_MAGENTA, "Error: not enough champions\n");
    else
        print_error_color(C_MAGENTA, "Error: too much champions\n");
    return (true);
}

int is_parameter_without_champ(char **av, int old_core, machine_t *machine)
{
    bool is_error = false;

    for (; av[old_core] && !is_error; old_core++) {
        if (my_strcmp(av[old_core], "-dump") && av[old_core + 1]) {
            is_error = fill_dump(av, old_core, machine);
            old_core++;
        } else
            return (1);
    }
    return (is_error ? 2 : 0);
}

bool parser(char **av, machine_t *machine)
{
    int old_core = 1;
    bool is_error = false;
    int error_type;

    for (int i = 1; !is_error && av[i]; i++) {
        if (is_file_core(av[i])) {
            is_error = open_file(av, machine, old_core, i);
            old_core = i + 1;
        }
    }
    error_type = is_parameter_without_champ(av, old_core, machine);
    if (!is_error && error_type > 0) {
        if (error_type == 1)
            print_error_color(C_MAGENTA, "Error: parameter without champion\n");
        return (true);
    }
    if (!is_error && ((*machine).total < 2 || (*machine).total > \
MAX_ARGS_NUMBER))
        return (print_error_nb_champ((*machine).total));
    return (is_error);
}
