/*
** EPITECH PROJECT, 2019
** asm
** File description:
** destroy_data.c
*/

#include "asm.h"

void destroy_lines(line_t *line)
{
    line_t *next_line = line ? line->next : NULL;

    for (; line && next_line; line = next_line, next_line = next_line->next) {
        if (line->line)
            free(line->line);
        if (line->args)
            free(line->args);
        free(line);
    }
    if (line) {
        if (line->line)
            free(line->line);
        if (line->args)
            free(line->args);
        free(line);
    }
}

void destroy_datas(int ac, data_t *data)
{
    for (int i = 0; i + 1 < ac; i++)
        destroy_lines(data[i].line);
    free(data);
}
