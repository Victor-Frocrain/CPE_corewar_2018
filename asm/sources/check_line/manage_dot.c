/*
** EPITECH PROJECT, 2019
** asm
** File description:
** manage_name.c
*/

#include "asm.h"

bool is_double_quote(char *line, int nb_line, int *size)
{
    bool is_first = false;
    bool is_second = false;

    for (int i = 0; line[i]; i++) {
        if (line[i] == '\"' && is_first && is_second) {
            print_line_error_color("too much quotes\n", nb_line);
            return (false);
        }
        if (line[i] == '\"' && !is_first)
            is_first = true;
        else if (line[i] == '\"' && !is_second)
            is_second = true;
        (*size) += (is_first && !is_second) ? 1 : 0;
    }
    if (!is_first || !is_second) {
        print_line_error_color("missing quotes\n", nb_line);
        return (false);
    }
    return (true);
}

void get_dotname(line_t *line, char *str)
{
    for (int j = 0, x = 0; line->args[0][j]; j++)
        if (line->args[0][j] != '\"')
            str[x++] = line->args[0][j];
}

bool manage_dot(line_t *line, char *ref, int length)
{
    int size = -1;

    if (!is_double_quote(line->args[0], line->nb_line, &size))
        return (true);
    if (line->args[0][0] != '\"' || \
line->args[0][my_strlen(line->args[0]) - 1] != '\"') {
        print_line_error_color("there is text outside quotes\n", line->nb_line);
        return (true);
    }
    if (size > length) {
        print_line_error_color(line->line, line->nb_line);
        my_puterror(" is too long\n");
        return (true);
    }
    get_dotname(line, ref);
    return (false);
}
