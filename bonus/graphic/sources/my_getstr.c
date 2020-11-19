/*
** EPITECH PROJECT, 2019
** my_getstr.c
** File description:
** pass int to str
*/

#include "graphic.h"

char *get_rate(char *str, char *str2, char *old_rate)
{
    char *res;
    char *res2;

    if (!(res = my_strcat(str, " / ")) || !(res2 = my_strcat(res, str2)))
        return (NULL);
    free(old_rate);
    free(res);
    return (res2);
}

char *new_rate(int life, char *rate, char *max_hp)
{
    if (life == 0)
        return (rate);
    return (get_rate(my_getstr(life), max_hp, rate));
}

char *my_getstr(int nb)
{
    char *str = NULL;
    int i = 1;
    int mult = 1;
    int j = 0;
    bool is_neg = false;

    (nb < 0) ? (i++, is_neg = true):0;
    for (; nb / (mult * 10) > 0; i++, mult *= 10);
    if (!(str = malloc(sizeof(char) * (i + 1))))
        return (NULL);
    (is_neg) ? (str[j++] = '-'):0;
    for (; j < i; j++) {
        str[j] = (nb / mult) + '0';
        nb -= (nb / mult) * mult;
        mult /= 10;
    }
    str[j] = 0;
    return (str);
}

bool is_str_dif_int(char *str, int nb)
{
    int strnb = my_getnbr(str);

    if (nb != strnb)
        return (true);
    return (false);
}
