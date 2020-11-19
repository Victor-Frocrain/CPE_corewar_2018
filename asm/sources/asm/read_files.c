/*
** EPITECH PROJECT, 2019
** asm
** File description:
** read_file.c
*/

#include "asm.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>

data_t ini_data(void)
{
    header_t header;
    int magic = COREWAR_EXEC_MAGIC;
    data_t data;
    const union {
        int i;
        char c[4];
    } e = {0x01000000};

    data.is_endian = !e.c[0];
    my_memset(header.prog_name, 0, PROG_NAME_LENGTH + 3);
    my_memset(header.comment, 0, COMMENT_LENGTH + 3);
    header.magic = data.is_endian ? reverse_int(magic) : magic;
    header.prog_size = 0;
    data.header = header;
    data.line = NULL;
    return (data);
}

void fill_line_after_label(line_t *line, bool *is_error)
{
    line_t *new_line = NULL;

    if (line->line[my_strlen(line->line) - 1] == LABEL_CHAR && \
line->nb_arg > 0 && !(*is_error)) {
        *is_error = line->args[0][my_strlen(line->args[0]) - 1] == LABEL_CHAR;
        new_line = malloc(sizeof(line_t));
        if (new_line && !(*is_error)) {
            new_line->next = NULL;
            new_line->line = my_strdup(line->args[0]);
            new_line->args = my_tabstrdup(line->args + 1);
            new_line->nb_arg = line->nb_arg - 1;
            line->nb_arg = 0;
            new_line->nb_line = line->nb_line;
            line->next = new_line;
        }
        *is_error = (*is_error || !new_line || !new_line->line || \
!new_line->args);
    }
}

bool fill_line(char *read, data_t *data, int nb_line, int size)
{
    line_t *line = NULL;
    line_t *lines = data->line;
    bool is_error = false;

    if (read[0] != '#' && size > 1) {
        line = malloc(sizeof(line_t));
        manage_instruct(read);
    }
    if (line && read[0] != '#' && size > 1 && my_strlen(read) > 0) {
        line->nb_line = nb_line;
        line->next = NULL;
        line->line = my_strdup(read);
        is_error = fill_instruct_arg(line);
        fill_line_after_label(line, &is_error);
        for (; lines && lines->next; lines = lines->next);
        if (!lines)
            (*data).line = line;
        else
            lines->next = line;
    }
    return ((!line && read[0] != '#' && size > 1) || is_error);
}

void read_a_file(char *str, bool *is_error, data_t *data)
{
    char *read = NULL;
    size_t reading = 0;
    FILE *to_read;
    int size;
    int line = 1;

    to_read = fopen(str, "r");
    for (; !(*is_error) && (size = getline(&read, &reading, to_read)) > 0; \
line++)
        (*is_error) = fill_line(read, data, line, size);
    if (size < 1 && line == 1) {
        print_error_color(C_MAGENTA, "Empty file\n", true);
        *is_error = true;
    }
    if (!(*is_error))
        *is_error = is_duplicate_label((*data).line);
    if (read)
        free(read);
    if (to_read)
        fclose(to_read);
}

int read_files(int ac, char **av)
{
    bool is_error = false;
    data_t *data = malloc(sizeof(data_t) * (ac - 1));

    for (int i = 1; data && i < ac; i++) {
        data[i - 1] = ini_data();
        read_a_file(av[i], &is_error, &data[i - 1]);
        if (!is_error)
            compile_and_write(av[i], &is_error, &data[i - 1]);
        if (is_error)
            my_puterror("\033[0m");
    }
    if (!is_error)
        destroy_datas(ac, data);
    return ((is_error || !data) ? (MY_ERROR) : (MY_SUCCESS));
}
