/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write_prog.c
*/

#include "asm.h"

void manage_mnemonic(int to_write, line_t *line, op_t op, data_t data)
{
    write(to_write, &op.code, 1);
    if (line->nb_arg > 1 || my_strcmp(line->line, "aff"))
        write_type(to_write, line);
    for (int i = 0; i < line->nb_arg; i++)
        write_arg(to_write, line, line->args[i], data);
}

void find_mnemonic(int to_write, line_t *line, data_t data)
{
    for (int i = 0; op_tab[i].mnemonique; i++)
        if (my_strcmp(line->line, op_tab[i].mnemonique))
            manage_mnemonic(to_write, line, op_tab[i], data);
}

void write_prog(int to_write, line_t *line, data_t data)
{
    for (line_t *lines = line; lines; lines = lines->next)
        find_mnemonic(to_write, lines, data);
}
