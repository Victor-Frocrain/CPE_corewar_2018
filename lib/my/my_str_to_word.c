/*
** EPITECH PROJECT, 2019
** my_str_to_word.c
** File description:
** Transform str in multiple array
*/

#include "my.h"

int calc_array(char *str)
{
    int count = 0;
    int i = 0;

    for (; str[i]; i++)
        if (str[i] != ' ' && str[i - 1] == ' ')
            count++;
    return (count);
}

char **my_str_to_array(char *str)
{
    int nb_array = calc_array(str);
    char **array = malloc(sizeof(char *) * (nb_array + 1));
    int x = 0;
    int y = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i - 1] == ' ')
            x++;
        if (str[i] != ' ') {
            array[x][y] = str[i];
            array[x] = my_realloc(array[x], y + 1);
            y++;
        }
    }
    array[nb_array] = NULL;
    return (array);
}
