/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** get_next_line
*/

#include "get_next_line.h"

char *calc_and_realloc(char *str, char *memory)
{
    int size = my_strlen(str) + my_strlen(memory) + 1;

    str = my_realloc(str, size);
    return (str);
}

bool fill_str(char **str, char *memory)
{
    int i = 0;

    if (!(*str) && memory) {
        (*str) = malloc(sizeof(char) * (my_strlen(memory) + 1));
        for (int j = 0; str && j < my_strlen(memory) + 1; j++)
            (*str)[j] = 0;
    } else
        (*str) = calc_and_realloc((*str), memory);
    if (!str)
        return (true);
    for (; (*str)[i]; i++);
    for (int j = 0; memory[j]; j++, i++)
        if (memory[j] == '\n') {
            (*str)[i] = 0;
            return (true);
        } else
            (*str)[i] = memory[j];
    (*str)[i] = 0;
    return (false);
}

char *delete_returned_and_return(char *str, char **memory, bool is_error)
{
    int i = 0;

    if (is_error) {
        free(str);
        return (NULL);
    }
    for (; *memory && (*memory)[i] && (*memory)[i] != '\n'; i++);
    if (!(*memory)[i++])
        return (str);
    (*memory) = (*memory) + i;
    return (str);
}

char *continue_reading(int fd, char **memory)
{
    int j = 0;
    char *str = NULL;

    if (fill_str(&str, (*memory)))
        return (delete_returned_and_return(str, &(*memory), false));
    j = read(fd, *memory, READ_SIZE);
    if (j <= 0)
        return (delete_returned_and_return(str, &(*memory), true));
    (*memory)[j] = 0;
    for (; !fill_str(&str, (*memory)) && j > 0; (*memory)[j] = 0)
        j = read(fd, *memory, READ_SIZE);
    return (delete_returned_and_return(str, &(*memory), false));
}

char *get_next_line(int fd)
{
    static char *memory = NULL;

    if (fd < 0 || READ_SIZE < 1)
        return (NULL);
    if (!memory) {
        memory = malloc(sizeof(char) * (READ_SIZE + 1));
        if (!memory)
            return (NULL);
        memory[0] = 0;
    }
    return (continue_reading(fd, &memory));
}
