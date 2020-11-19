/*
** EPITECH PROJECT, 2018
** my_power.c
** File description:
** Calc the power of nb
*/

int my_power(int nb, int p)
{
    if (p <= 0)
        return (0);
    for (; p > 1; p--)
        nb *= nb;
    return (nb);
}
