/*
** EPITECH PROJECT, 2019
** asm
** File description:
** calc_label_dist.c
*/

#include "asm.h"

bool is_instruct(char *str)
{
    for (int i = 0; op_tab[i].mnemonique; i++)
        if (my_strcmp(str, op_tab[i].mnemonique))
            return (true);
    return (false);
}

void count_instruct_byte(line_t *line, int *count, data_t data)
{
    if (line->line[my_strlen(line->line) - 1] == LABEL_CHAR)
        return;
    (*count)++;
    if (line->nb_arg > 1 || my_strcmp("aff", line->line))
        (*count)++;
    for (int i = 0; i < line->nb_arg; i++)
        is_arg_correct(line->args[i], T_DIR | T_IND | T_REG, data, count);
}

bool is_label_found(char *str, line_t *line)
{
    int i = 0;

    if (line->line[my_strlen(line->line) - 1] != LABEL_CHAR)
        return (false);
    for (; line->line[i] && line->line[i] != LABEL_CHAR; i++)
        if (line->line[i] != str[i])
            return (false);
    return (line->line[i] == LABEL_CHAR && !str[i]);
}

bool is_label_called_before_ini(char *str, line_t *line, line_t *lines)
{
    if (lines == line)
        return (true);
    if (is_label_found(str, lines))
        return (false);
    return (is_label_called_before_ini(str, line, lines->next));
}

int calc_label_dist(char *str, line_t *line, data_t data)
{
    bool is_neg = is_label_called_before_ini(str, line, data.line);
    int count = (is_neg) ? 1 : -1;
    line_t *lines = (is_neg) ? line->next : data.line;

    if (is_neg)
        count_instruct_byte(line, &count, data);
    for (; lines && !is_label_found(str, lines); lines = lines->next)
        if (is_neg)
            count_instruct_byte(lines, &count, data);
    for (; !is_neg && lines && lines != line; lines = lines->next)
        if (is_instruct(lines->line))
            count_instruct_byte(lines, &count, data);
    return ((is_neg) ? -count : count);
}
