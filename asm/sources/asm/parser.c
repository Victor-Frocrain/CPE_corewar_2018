/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** parser.c
*/

#include "asm.h"
#include <fcntl.h>

bool is_right_extension(char *extension, char *str)
{
    int i = my_strlen(str) - 1;

    for (; i >= 0 && str[i] != '.'; i--);
    return (my_strcmp(extension, str + i));
}

void print_file_error(char *file, char *error)
{
    my_puterror("Error: ");
    my_puterror(file);
    my_puterror(" ");
    my_puterror(error);
}

bool is_assembly_file(char *str)
{
    int fd = open(str, O_RDONLY);

    if (fd < 0) {
        print_file_error(str, "can't be openned\n");
        return (false);
    }
    close(fd);
    if (!is_right_extension(".s", str)) {
        print_file_error(str, "wrong file type\n");
        return (false);
    }
    return (true);
}

bool is_arguments_error(int ac, char **av)
{
    if (ac < 2) {
        my_puterror("Error: wrong number of argument\n");
        return (true);
    }
    for (int i = 1; i < ac; i++)
        if (!is_assembly_file(av[i]))
            return (true);
    return (false);
}
