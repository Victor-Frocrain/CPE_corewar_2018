/*
** EPITECH PROJECT, 2019
** asm
** File description:
** check_arg_type.c
*/

#include "asm.h"

bool is_register(char *arg, bool *is_error, int *prog_size)
{
    if (arg[0] != 'r')
        return (false);
    if (!is_str_int(arg + 1))
        *is_error = true;
    if (!(*is_error) && my_getnbr(arg + 1) > REG_NUMBER)
        *is_error = true;
    (*prog_size) += 1;
    return (true);
}

bool is_direct(char *arg, line_t *line, bool *is_error, int *prog_size)
{
    line_t *lines = line;
    bool is_index;
    bool is_found = false;

    while (!is_found && lines) {
        for (int i = 0; i < lines->nb_arg && !is_found; i++)
            is_found = lines->args[i] == arg;
        if (!is_found)
            lines = lines->next;
    }
    if (lines)
        is_index = is_instruct_index(lines->line);
    if (arg[0] != DIRECT_CHAR)
        return (false);
    (*prog_size) += (is_index) ? 2 : DIR_SIZE;
    if (is_str_int(arg + 1) || is_label(arg + 1, line, is_error))
        return (true);
    *is_error = true;
    return (true);
}

bool is_indirect(char *arg, line_t *line, bool *is_error, int *prog_size)
{
    bool is_index = is_instruct_index(line->line);

    (*prog_size) += (is_index) ? 2 : IND_SIZE;
    if (is_str_int(arg) || is_label(arg, line, is_error))
        return (true);
    *is_error = true;
    return (false);
}

bool is_existing_label(line_t *line, char *label)
{
    char *copy = my_strcat(label, ":");

    for (line_t *lines = line; copy && lines; lines = lines->next)
        if (my_strcmp(copy, lines->line)) {
            free(copy);
            return (true);
        }
    if (copy)
        free(copy);
    return (false);
}

bool is_label(char *arg, line_t *line, bool *is_error)
{
    if (arg[0] != LABEL_CHAR)
        return (false);
    *is_error = !is_existing_label(line, arg + 1);
    return (true);
}
