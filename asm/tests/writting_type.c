/*
** EPITECH PROJECT, 2019
** asm
** File description:
** test writting type
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

char *read_file(char *filepath);

Test(Asm, write_reg)
{
    int fd = open("filepath", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    char *arg[] = {"r2", "23", "%34", NULL};
    line_t *line = malloc(sizeof(line_t));
    char *res;
    data_t data = ini_data();

    line->nb_arg = 3;
    line->args = arg;
    line->line = "and";
    write_arg(fd, line, line->args[0], data);
    close(fd);
    res = read_file("filepath");
    cr_expect_eq(0x02, res[0]);
    free(line);
    free(res);
    remove("filepath");
}

Test(Asm, write_ind)
{
    int fd = open("filepath2", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    char *arg[] = {"r2", "23", "%34", NULL};
    line_t *line = malloc(sizeof(line_t));
    char *res;
    data_t data = ini_data();

    line->nb_arg = 3;
    line->args = arg;
    line->line = "and";
    write_arg(fd, line, line->args[1], data);
    close(fd);
    res = read_file("filepath2");
    cr_expect_eq(0x00, res[0]);
    cr_expect_eq(0x17, res[1]);
    free(line);
    free(res);
    remove("filepath2");
}

Test(Asm, write_dir)
{
    int fd = open("filepath4", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    char *arg[] = {"r2", "23", "%34", NULL};
    line_t *line = malloc(sizeof(line_t));
    char *res;
    data_t data = ini_data();

    line->nb_arg = 3;
    line->args = arg;
    line->line = "sti";
    write_arg(fd, line, line->args[2], data);
    close(fd);
    res = read_file("filepath4");
    cr_expect_eq(0x00, res[0]);
    cr_expect_eq(0x22, res[1]);
    free(line);
    free(res);
    remove("filepath4");
}

Test(Asm, write_label)
{
    int fd = open("filepath3", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    char expected1 = 0xff;
    char expected2 = 0xfb;
    char *res;
    data_t data = ini_data();
    bool is_error = false;
    line_t *line;

    read_a_file("tests/example.s", &is_error, &data);
    cr_assert(!is_error);
    for (line = data.line; line->next; line = line->next);
    write_arg(fd, line, line->args[0], data);
    close(fd);
    res = read_file("filepath3");
    cr_expect_eq(expected1, res[0]);
    cr_expect_eq(expected2, res[1]);
    remove("filepath3");
}
