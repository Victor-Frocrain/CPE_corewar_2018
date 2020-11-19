/*
** EPITECH PROJECT, 2019
** disasm
** File description:
** fill_asm.c
*/

#include "disasm.h"

void write_header(int fd, header_t header)
{
    write(fd, ".name \"", my_strlen(".name \""));
    write(fd, header.prog_name, my_strlen(header.prog_name));
    write(fd, "\"\n", 2);
    if (my_strlen(header.comment) > 0) {
        write(fd, ".comment \"", my_strlen(".comment \""));
        write(fd, header.comment, my_strlen(header.comment));
        write(fd, "\"\n", 2);
    }
    write(fd, "\n", 1);
}

void jump_to_next_instruct(instruct_t instruct, int *pc)
{
    int nb_byte = 1;
    bool is_index = is_instruct_index(instruct.code);
    short *mask = instruct.mask;

    if (!(instruct.nb_arg == 1 && instruct.code != 0x10))
        nb_byte++;
    for (int i = 0; i < instruct.nb_arg; i++) {
        if (mask[i] == REGISTER)
            nb_byte++;
        if (mask[i] == DIRECT && !is_index)
            nb_byte += 4;
        if (mask[i] == INDIRECT || (is_index && mask[i] == DIRECT))
            nb_byte += 2;
    }
    *pc += nb_byte;
}

char *get_prefix(short mask)
{
    if (mask == REGISTER)
        return ("r");
    if (mask == DIRECT)
        return ("%");
    return (0);
}

void write_arg(int fd, instruct_t instruct)
{
    char *name = op_tab[instruct.code - 1].mnemonique;
    bool is_index = is_instruct_index(instruct.code);
    int nb;

    write(fd, name, my_strlen(name));
    for (int i = 0; i < instruct.nb_arg; i++) {
        if (instruct.mask[i] == REGISTER)
            nb = instruct.arg[i][0];
        if (instruct.mask[i] == DIRECT)
            nb = is_index ? reverse_short(*(short *)(instruct.arg[i])) : \
reverse_int(*(int *)(instruct.arg[i]));
        if (instruct.mask[i] == INDIRECT)
            nb = reverse_short(*(short *)(instruct.arg[i]));
        write(fd, " ", 1);
        if (instruct.mask[i] == REGISTER || instruct.mask[i] == DIRECT)
            write(fd, get_prefix(instruct.mask[i]), 1);
        my_printfd(fd, "%d", nb);
        if (i != instruct.nb_arg - 1)
            write(fd, ",", 1);
    }
    write(fd, "\n", 1);
}

void write_asm(int fd, char *file, header_t header)
{
    instruct_t instruct;

    instruct.nb_arg = 0;
    instruct.code = 0;
    for (int i = 0; i < 3; i++) {
        instruct.mask[i] = 0;
        for (int j = 0; j < 4; j++)
            instruct.arg[i][j] = 0;
    }
    write_header(fd, header);
    for (int i = 0; i < header.prog_size;) {
        fill_instruct(&instruct, file + i);
        jump_to_next_instruct(instruct, &i);
        write_arg(fd, instruct);
    }
}
