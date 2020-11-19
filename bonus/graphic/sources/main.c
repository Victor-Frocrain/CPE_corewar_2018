/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "corewar.h"

int main(int ac, char **av)
{
    if (REST < 0)
        return (MY_ERROR);
    return (corewar(ac, av));
}
