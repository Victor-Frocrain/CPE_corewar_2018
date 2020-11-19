/*
** EPITECH PROJECT, 2019
** disasm
** File description:
** create_cor_file.c
*/

#include "disasm.h"
#include <fcntl.h>

void fill_asm_name(char *asm_name, char *file_name)
{
    int b_ext = my_strlen(file_name) - 1;
    int i = 0;

    for (; b_ext >= 0 && file_name[b_ext] != '.'; b_ext--);
    for (; i != b_ext; i++)
        asm_name[i] = file_name[i];
    asm_name[i++] = '.';
    asm_name[i++] = 's';
    asm_name[i] = 0;
}

int create_asm_file(char *file_name)
{
    int fd;
    char *asm_name = malloc(sizeof(char) * (my_strlen(file_name) - 1));
    mode_t give_acces = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    mode_t create_file = O_WRONLY | O_CREAT | O_TRUNC;

    fill_asm_name(asm_name, file_name);
    fd = open(asm_name, create_file, give_acces);
    free(asm_name);
    return (fd);
}
