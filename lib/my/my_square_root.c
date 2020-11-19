/*
** EPITECH PROJECT, 2019
** my_compute_square_root.c
** File description:
** Calc the intergers square root of nb
*/

int my_square_root(int nb)
{
    int i = (1 + nb) / 2;
    int j = 1;
    int comp = 0;
    int rec = i;

    while (rec > comp) {
        rec = i;
        i = (i + nb / i) / 2;
        comp = i;
    }
    if (i * i != nb)
        return (0);
    return (i);
}
