/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write_type.c
*/

#include "asm.h"

void print_label(int to_write, line_t *line, char *str, data_t data)
{
    bool is_indirect = str[0] == LABEL_CHAR;
    int dist_to_label;
    int res;
    bool is_short = is_instruct_index(line->line) || is_indirect;

    if (is_indirect)
        dist_to_label = calc_label_dist(str + 1, line, data);
    else
        dist_to_label = calc_label_dist(str, line, data);
    if (dist_to_label < 0)
        res = 0x0000 - dist_to_label - 1;
    else
        res = 0xFFFF - dist_to_label;
    if (data.is_endian) {
        if (is_short) {
            res = reverse_short(res);
        } else
            res = reverse_int(res);
    }
    write(to_write, &res, is_short ? 2 : 4);
}

void write_arg(int to_write, line_t *line, char *str, data_t data)
{
    char *nb = (str[0] == 'r' || str[0] == DIRECT_CHAR) ? (str + 1) : (str);
    int res = my_getnbr(nb);
    bool is_index = is_instruct_index(line->line);
    bool is_indirect = (str[0] != 'r' && str[0] != LABEL_CHAR && \
str[0] != DIRECT_CHAR);
    bool is_label = (str[0] == LABEL_CHAR || str[1] == LABEL_CHAR);

    if (data.is_endian && str[0] != 'r')
        res = (str[0] == DIRECT_CHAR && !is_index) ? reverse_int(res) : \
reverse_short(res);
    if (str[0] == 'r')
        write(to_write, &res, 1);
    if (str[0] == DIRECT_CHAR && str[1] != LABEL_CHAR)
        write(to_write, &res, is_index ? 2 : DIR_SIZE);
    if (is_indirect)
        write(to_write, &res, IND_SIZE);
    if (is_label)
        print_label(to_write, line, str + (str[0] == LABEL_CHAR ? 0 : 2), data);
}

void write_type(int to_write, line_t *line)
{
    int res = 0x00;
    int arg_type = 0b00;
    int i = 0;

    for (; i < line->nb_arg; i++) {
        if (line->args[i][0] == 'r')
            arg_type = 0b01;
        else if (line->args[i][0] == DIRECT_CHAR)
            arg_type = 0b10;
        else
            arg_type = 0b11;
        res |= arg_type << (-(i - 3) * 2);
    }
    write(to_write, &res, 1);
}
