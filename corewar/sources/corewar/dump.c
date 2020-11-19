/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** dump function
*/

#include "corewar.h"

void get_char_hexa(int nb, char res[2])
{
    int nbs[2] = {(nb >> 4) & 0xF, nb & 0xF};

    for (int i = 0; i < 2; i++)
        res[i] = nbs[i] < 10 ? nbs[i] + '0' : nbs[i] + 'A' - 10;
}

void print_a_line(int x, char *map)
{
    char line[32 * (2 + 1) + 2];
    int j = 0;
    char hexa[2];

    for (int i = 0; i < 32 && x + i < MEM_SIZE; i++) {
        get_char_hexa(map[i + x], hexa);
        line[j++] = ' ';
        line[j++] = hexa[0];
        line[j++] = hexa[1];
    }
    line[j++] = '\n';
    line[j] = 0;
    write(1, &line, my_strlen(line));
}

void print_line(int nb, int max_size)
{
    char line[max_size + 3];
    int size = 1;

    for (; nb >> size * 4; size++);
    for (int i = size - 1, j = 0; i >= 0; i--, j++) {
        line[j] = (nb >> (i * 4)) & 0xF;
        line[j] += line[j] < 10 ? '0' : 'A' - 10;
    }
    for (int i = size; i < max_size + 1; i++)
        line[i] = ' ';
    line[max_size + 1] = ':';
    line[max_size + 2] = 0;
    write(1, line, my_strlen(line));
}

void dump(machine_t machine)
{
    int max_size = 1;

    for (; MEM_SIZE >> max_size * 4; max_size++);
    for (int i = 0; i < MEM_SIZE; i += 32) {
        print_line(i, max_size);
        print_a_line(i, machine.map);
    }
}
