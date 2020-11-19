/*
** EPITECH PROJECT, 2019
** asm
** File description:
** create_instruct_args.c
*/

#include "asm.h"

int count_args(char *line)
{
    int i = 0;
    int count = 0;

    if (line[0])
        count++;
    if (line[i] && line[i] == '\"')
        for (++i; line[i] && (i <= 1 || line[i - 1] != '\"'); i++);
    else
        for (; line[i] && line[i] != ' ' && line[i] != SEPARATOR_CHAR; i++);
    for (; line[i] && (line[i] == ' ' || line[i] == SEPARATOR_CHAR); i++);
    return ((!line[i]) ? count - 1: count + count_args(line + i));
}

void passed_string_with_quotes(char *str, int *i)
{
    if (str[*i] == '\"')
        for ((*i)++; str[*i] && str[*i] != '\"'; (*i)++);
}

void fill_arg(line_t *line, char *str, int nb_arg)
{
    int j = 0;

    for (; str[j] && str[j] != ' '; j++);
    if (str[j])
        str[j++] = 0;
    for (int i = 0; i < nb_arg; i++) {
        line->args[i] = str + j;
        for (; str[j] && str[j] != SEPARATOR_CHAR && str[j] != ' '; j++)
            passed_string_with_quotes(str, &j);
        if (str[j])
            str[j++] = 0;
        for (; str[j] && (str[j] == ' ' || str[j] == SEPARATOR_CHAR); j++);
    }
}

bool fill_instruct_arg(line_t *line)
{
    line->args = NULL;
    line->nb_arg = count_args(line->line);
    if (line->nb_arg > 0) {
        line->args = malloc(sizeof(char *) * (line->nb_arg + 1));
        if (line->args) {
            fill_arg(line, line->line, line->nb_arg);
            line->args[line->nb_arg] = NULL;
        }
    }
    return (line->nb_arg > 0 && !line->args);
}
