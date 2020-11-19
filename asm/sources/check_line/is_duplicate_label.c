/*
** EPITECH PROJECT, 2019
** asm
** File description:
** is_duplicate_label.c
*/

#include "asm.h"

bool is_label_seen(line_t *line, char *label)
{
    for (line_t *lines = line; lines; lines = lines->next)
        if (my_strcmp(lines->line, label))
            return (true);
    return (false);
}

bool is_duplicate_label(line_t *line)
{
    bool is_error = false;

    for (line_t *lines = line; lines && !is_error; lines = lines->next) {
        if (lines->line[my_strlen(lines->line) - 1] == LABEL_CHAR)
            is_error = is_label_seen(lines->next, lines->line);
    }
    return (is_error);
}
