/*
** EPITECH PROJECT, 2019
** asm
** File description:
** create_cor_file.c
*/

#include "asm.h"
#include <fcntl.h>

int get_cor_name_size(char *file_name)
{
    int ext = my_strlen(file_name) - 1;
    int o_size = my_strlen(file_name);
    int ext_size;

    for (; file_name[ext] != '.'; ext--);
    ext_size = o_size - (o_size - (ext + 1));
    return (ext_size + my_strlen("cor") + 1);
}

void fill_cor_name(char *cor_name, char *file_name)
{
    int b_ext = my_strlen(file_name) - 1;
    int i = 0;
    char *cor = ".cor";

    for (; b_ext >= 0 && file_name[b_ext] != '.'; b_ext--);
    for (; i != b_ext; i++)
        cor_name[i] = file_name[i];
    for (int j = 0; cor[j]; j++, i++)
        cor_name[i] = cor[j];
    cor_name[i] = 0;
}

int create_cor_file(char *file_name)
{
    int fd;
    bool is_error = true;
    char *cor_name = malloc(sizeof(char) * get_cor_name_size(file_name));
    mode_t give_acces = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    mode_t create_file = O_WRONLY | O_CREAT | O_TRUNC;

    if (cor_name) {
        is_error = false;
        fill_cor_name(cor_name, file_name);
        fd = open(cor_name, create_file, give_acces);
        free(cor_name);
    }
    return ((is_error) ? -1 : fd);
}
