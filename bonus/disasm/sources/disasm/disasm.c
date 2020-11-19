/*
** EPITECH PROJECT, 2019
** disasm
** File description:
** disasm.c
*/

#include "disasm.h"
#include <sys/stat.h>
#include <fcntl.h>

bool fill_header(int fd, header_t *header)
{
    read(fd, header, sizeof(header_t));
    header->prog_size = reverse_int(header->prog_size);
    header->magic = reverse_int(header->magic);
    if (header->prog_size < 0)
        return (false);
    if (COREWAR_EXEC_MAGIC != header->magic)
        return (false);
    return (true);
}

char *fill_file(char *filepath, header_t *header)
{
    struct stat info;
    char *str;
    int fd = open(filepath, O_RDONLY);
    int size;

    if (!fill_header(fd, header))
        return (NULL);
    stat(filepath, &info);
    str = malloc(sizeof(char) * (header->prog_size + 1));
    if (!str)
        return (NULL);
    size = read(fd, str, header->prog_size);
    if (size != header->prog_size) {
        print_error_color(C_RED, "Error: wrong header\n", true);
        return (NULL);
    }
    str[header->prog_size] = 0;
    close(fd);
    return (str);
}

int disasm(int ac, char **av)
{
    int fd;
    char *file;
    header_t header;

    for (int i = 1; i < ac; i++) {
        file = fill_file(av[i], &header);
        if (!file)
            return (MY_ERROR);
        fd = create_asm_file(av[i]);
        if (fd == -1)
            return (MY_ERROR);
        write_asm(fd, file, header);
        free(file);
        close(fd);
    }
    return (MY_SUCCESS);
}
