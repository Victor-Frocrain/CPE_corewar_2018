/*
** EPITECH PROJECT, 2019
** fill_instruct_after_label
** File description:
** fill_instruct_after_label function
*/

#include "asm.h"

bool fill_instruct_after_label(line_t *line)
{
    line_t *new_line = NULL;

    my_printf("%s\n", line->line);
    for (int i = 0; i < line->nb_arg; i++)
        my_printf("%s\n", line->args[i]);
    new_line = malloc(sizeof(line_t));
    if (new_line) {
        new_line->next = NULL;
        line->next = new_line;
        new_line->nb_arg = line->nb_arg - 1;
        new_line->line = line->args[0];
        new_line->args = line->args + 1;
        new_line->nb_line = line->nb_line;
        line->nb_arg = 0;
        line->args = NULL;
    }
    my_printf("Name: %s\nnb_arg: %d\n", new_line->line, new_line->nb_arg);
    for (int i = 0; i < new_line->nb_arg; i++)
        my_printf("%s\n", new_line->args[i]);
    return (new_line);
}
