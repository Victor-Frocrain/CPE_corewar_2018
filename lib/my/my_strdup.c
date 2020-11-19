/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** Allocate a space for a string
*/

#include "my.h"

char *my_strdup(char *str)
{
    int i = 0;
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (; str[i]; i++)
        result[i] = str[i];
    result[i] = 0;
    return (result);
}

int count_str(char **tabstr)
{
    int count = 0;

    for (; tabstr[count]; count++);
    return (count);
}

char **my_tabstrdup(char **tabstr)
{
    int size = count_str(tabstr);
    char **new_tab = malloc(sizeof(char *) * (size + 1));

    if (!new_tab)
        return (NULL);
    for (int i = 0; i < size; i++)
        new_tab[i] = tabstr[i];
    new_tab[size] = NULL;
    return (new_tab);
}
