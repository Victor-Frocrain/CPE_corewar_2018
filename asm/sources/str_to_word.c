/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my.h"
#include <sys/stat.h>

int count_line(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        (str[i] == c && str[i + 1]) ? count++:0;
    return (count + 1);
}

int next_line(char *str, char c)
{
    int count = 0;

    for (; str[count] && str[count] != c; count++);
    str[count] = 0;
    return (count + 1);
}

char **str_to_word(char *str, char c)
{
    int nb_line = count_line(str, c);
    char **map = malloc(sizeof(char *) * (nb_line + 1));

    if (!map)
        return (NULL);
    map[0] = str;
    for (int i = 1, next = next_line(str, c); i < nb_line; \
i++, next += next_line(str + next, c)) {
        map[i] = str + next;
    }
    map[nb_line] = NULL;
    return (map);
}

char **open_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat info;
    char *str;

    if (fd < 0 || stat(filepath, &info) == -1 || !(str = malloc(sizeof(char) * \
(info.st_size + 1))))
        return (NULL);
    for (int i = 0, read_size = 0; (read_size = \
read(fd, str + i, info.st_size)) + i != info.st_size; i += read_size);
    str[info.st_size] = 0;
    return (str_to_word(str, '\n'));
}
