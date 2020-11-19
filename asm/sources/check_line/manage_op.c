/*
** EPITECH PROJECT, 2019
** asm
** File description:
** manage op
*/

#include "asm.h"

bool is_arg_correct(char *arg, args_type_t type, data_t data, int *prog_size)
{
    bool is_type_found = false;
    bool is_error = false;

    if (type & T_REG)
        is_type_found = is_register(arg, &is_error, prog_size);
    if (!is_type_found && type & T_DIR)
        is_type_found = is_direct(arg, data.line, &is_error, prog_size);
    if (!is_type_found && type & T_IND)
        is_type_found = is_indirect(arg, data.line, &is_error, prog_size);
    return (is_type_found && !is_error);
}

bool is_args_correct(line_t *line, op_t op, data_t data, int *prog_size)
{
    (*prog_size)++;
    if (line->nb_arg > 1 || my_strcmp(line->line, "aff"))
        (*prog_size)++;
    if (line->nb_arg != op.nbr_args) {
        print_line_error_color("wrong number of parameter\n", line->nb_line);
        return (false);
    }
    for (int i = 0; i < line->nb_arg; i++)
        if (!is_arg_correct(line->args[i], op.type[i], data, prog_size)) {
            print_line_error_color("wrong type of parameter\n", line->nb_line);
            return (false);
        }
    return (true);
}

bool is_right_label(line_t *line)
{
    bool is_label_char = false;

    if (line->line[my_strlen(line->line) - 1] != LABEL_CHAR)
        return (false);
    for (int i = 0; line->line[i] && line->line[i] != LABEL_CHAR; i++) {
        is_label_char = false;
        for (int j = 0; !is_label_char && LABEL_CHARS[j]; j++)
            is_label_char = line->line[i] == LABEL_CHARS[j];
        if (!is_label_char) {
            print_line_error_color("wrong label name, should only \
contain LABEL_CHARS\n", line->nb_line);
            return (false);
        }
    }
    return (true);
}

bool is_instruct_correct(line_t *line, data_t data, int *prog_size)
{
    bool is_error = false;
    bool is_found = false;

    for (int i = 0; !is_error && !is_found && op_tab[i].mnemonique; i++)
        if (my_strcmp(line->line, op_tab[i].mnemonique)) {
            is_found = true;
            is_error = !is_args_correct(line, op_tab[i], data, prog_size);
        }
    if (!is_found)
        return (is_right_label(line));
    return (!is_error);
}

bool is_instructs_correct(data_t data, int *prog_size)
{
    for (line_t *lines = data.line; lines; lines = lines->next)
        if (!my_strcmp(lines->line, ".name") && !my_strcmp(lines->line, \
".comment") && !is_instruct_correct(lines, data, prog_size)) {
            return (false);
        }
    return (true);
}
