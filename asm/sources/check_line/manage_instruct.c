/*
** EPITECH PROJECT, 2019
** asm
** File description:
** manage_instruct.c
*/

#include "asm.h"

void remove_useless_char(char *str)
{
    int i = 0;

    for (int j = 1; str[j]; i++, j++)
        str[i] = str[j];
    str[i] = 0;
}

bool is_useless_char(char *str, int i)
{
    if (str[0] == '\n')
        return (true);
    if (str[0] == ' ')
        if (i == 0 || str[1] == ' ' || !str[1] || str[1] == '\n' || \
str[1] == COMMENT_CHAR)
            return (true);
    return (false);
}

void manage_instruct(char *line)
{
    bool is_under_quote = false;
    bool is_end_of_line = false;

    for (int i = 0; line[i]; i++)
        if (line[i] == '\t')
            line[i] = ' ';
    for (int i = 0; line[i];) {
        if (line[i] == COMMENT_CHAR)
            is_end_of_line = true;
        if (line[i] == '\"')
            is_under_quote = !is_under_quote;
        if ((is_useless_char(line + i, i) && !is_under_quote) || is_end_of_line)
            remove_useless_char(line + i);
        else
            i++;
    }
}
