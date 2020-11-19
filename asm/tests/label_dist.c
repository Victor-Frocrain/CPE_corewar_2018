/*
** EPITECH PROJECT, 2019
** asm
** File description:
** label_dist
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <fcntl.h>
#include <stdio.h>

bool is_label_called_before_ini(char *str, line_t *line, line_t *lines);
void count_instruct_byte(line_t *line, int *count, data_t data);
void print_label(int to_write, line_t *line, char *str, data_t data);
char *read_file(char *filepath);

Test(Asm, is_label_called_before_ini)
{
    line_t *line = malloc(sizeof(line_t));

    line->next = malloc(sizeof(line_t));
    line->next->line = "live:";
    line->line = "zjmp";
    cr_assert(is_label_called_before_ini("live", line, line));
    free(line->next);
    free(line);
}

Test(Asm, label_called_before_ini)
{
    data_t data = ini_data();
    line_t *line = malloc(sizeof(line_t));

    line->next = malloc(sizeof(line_t));
    line->next->next = malloc(sizeof(line_t));
    line->next->line = "add";
    line->next->next->line = "live:";
    line->line = "zjmp";
    data.line = line;
    cr_assert_eq(calc_label_dist("live", line, data), -3);
    free(line->next->next);
    free(line->next);
    free(line);
}

Test(Asm, dont_inc_when_label)
{
    data_t data = ini_data();
    line_t line;
    int count = 0;

    line.line = "l2:";
    count_instruct_byte(&line, &count, data);
    cr_assert_eq(count, 0);
}

Test(Asm, print_direct_label)
{
    int fd = open("filepath10", O_CREAT | O_WRONLY | O_TRUNC, \
S_IRUSR | S_IWUSR);
    data_t data = ini_data();
    line_t *line = malloc(sizeof(line_t));
    char *arg[] = {"%:label", "r1", NULL};

    line->line = "lld";
    line->args = arg;
    line->nb_arg = 2;
    line->nb_line = 2;
    line->next = malloc(sizeof(line_t));
    line->next->line = ":label";
    line->next->next = NULL;
    data.line = line;
    print_label(fd, line, "label", data);
    close(fd);
    remove("filepath10");
}
