/*
** EPITECH PROJECT, 2019
** asm
** File description:
** compile_and_write.c
*/

#include "asm.h"

bool is_dot_name(line_t *line)
{
    if (!my_strcmp(line->line, ".name")) {
        print_line_error_color(".name is undefined or misplaced\n", \
line->nb_line);
        return (false);
    }
    if (line->nb_arg != 1) {
        if (line->nb_arg > 1)
            print_line_error_color("too much arguments\n", line->nb_line);
        else
            print_line_error_color("too few arguments\n", line->nb_line);
        return (false);
    }
    for (line_t *cpy_line = line->next; cpy_line; cpy_line = cpy_line->next)
        if (my_strcmp(cpy_line->line, ".name")) {
            print_line_error_color("multiple declaration of .name\n", \
cpy_line->nb_line);
            return (false);
        }
    return (true);
}

bool is_dot_comment(line_t *line, bool *is_error)
{
    if (!my_strcmp(line->line, ".comment"))
        return (false);
    if (line->nb_arg != 1) {
        if (line->nb_arg > 1)
            print_line_error_color("too much arguments\n", line->nb_line);
        else
            print_line_error_color("too few arguments\n", line->nb_line);
        *is_error = true;
        return (false);
    }
    for (line_t *cpy_line = line->next; cpy_line; cpy_line = cpy_line->next)
        if (my_strcmp(cpy_line->line, ".comment")) {
            print_line_error_color("multiple declaration of .comment\n", \
cpy_line->nb_line);
            *is_error = true;
            return (false);
        }
    return (true);
}

void fill_dot(bool *is_error, data_t *data)
{
    line_t *line = (*data).line;
    bool is_comment = false;

    *is_error = !is_dot_name(line);
    if (!(*is_error) && line->next)
        is_comment = is_dot_comment(line->next, is_error);
    if (!(*is_error))
        *is_error = manage_dot(line, (*data).header.prog_name, \
PROG_NAME_LENGTH);
    if (is_comment && !(*is_error))
        *is_error = manage_dot(line->next, (*data).header.comment, \
COMMENT_LENGTH);
}

void compile_and_write(char *str, bool *is_error, data_t *data)
{
    int to_write;

    fill_dot(is_error, data);
    if (!(*is_error))
        *is_error = !is_instructs_correct(*data, &(*data).header.prog_size);
    if (!(*is_error)) {
        to_write = create_cor_file(str);
        *is_error = (to_write < 0);
    }
    if (!(*is_error)) {
        if ((*data).is_endian)
            (*data).header.prog_size = reverse_int((*data).header.prog_size);
        write(to_write, &(*data).header, sizeof(header_t));
        write_prog(to_write, (*data).line, *data);
    }
}
