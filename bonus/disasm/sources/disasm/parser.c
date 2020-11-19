/*
** EPITECH PROJECT, 2019
** disasm
** File description:
** parser.c
*/

#include "disasm.h"
#include <fcntl.h>

bool is_right_extension(char *file_name, char *extension)
{
    int i = my_strlen(file_name) - 1;

    for (; i >= 0 && file_name[i] != '.'; i--);
    return (my_strcmp(file_name + i, extension));
}

bool is_file_correct(char *filepath)
{
    if (!is_right_extension(filepath, ".cor")) {
        print_error_color(C_RED, "Error: disasm need file[.cor]\n", true);
        return (false);
    }
    return (true);
}

bool is_existing_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    bool ret = fd != -1;

    close(fd);
    return (ret);
}

bool parser(int ac, char **av)
{
    if (ac <= 1) {
        print_error_color(C_RED, "Error: disasm need argument\n", true);
        return (true);
    }
    for (int i = 1; i < ac; i++) {
        if (!is_file_correct(av[i]))
            return (true);
        if (!is_existing_file(av[i]))
            return (true);
    }
    return (false);
}
