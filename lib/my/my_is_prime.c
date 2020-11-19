/*
** EPITECH PROJECT, 2019
** my_is_prime.c
** File description:
** Is the number prime ?
*/

#include "my.h"

bool my_is_prime(int nb)
{
    if (nb <= 1)
        return (false);
    for (int i = 2; i < nb; i++)
        if (nb % i == 0)
            return (false);
    return (true);
}
