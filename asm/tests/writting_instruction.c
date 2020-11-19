/*
** EPITECH PROJECT, 2019
** ams
** File description:
** test writting instruction
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <sys/stat.h>

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *res;
    struct stat info;

    stat(filepath, &info);
    if (fd < 0 || info.st_size == 0 || \
!(res = malloc(sizeof(char) * (info.st_size + 1))))
        return (NULL);
    read(fd, res, info.st_size);
    res[info.st_size] = 0;
    close(fd);
    return (res);
}

Test(Asm, write_type)
{
    int fd = open("filepath5", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    char *arg[] = {"r2", "23", "%34", NULL};
    line_t *line = malloc(sizeof(line_t));
    char *res;

    line->nb_arg = 3;
    line->args = arg;
    line->line = "and";
    write_type(fd, line);
    close(fd);
    res = read_file("filepath5");
    cr_assert_eq(0x78, res[0]);
    free(line);
    free(res);
    remove("filepath5");
}

Test(Asm, indirect_label)
{
    int fd = open("filepath6", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    char expected1 = 0xff;
    char expected2 = 0xfb;
    char *res;
    data_t data = ini_data();
    bool is_error = false;
    line_t *line;

    read_a_file("tests/indirect_label.s", &is_error, &data);
    cr_assert(!is_error);
    for (line = data.line; line->next; line = line->next);
    write_arg(fd, line, line->args[1], data);
    close(fd);
    res = read_file("filepath6");
    cr_expect_eq(expected1, res[0]);
    cr_expect_eq(expected2, res[1]);
    free(res);
    remove("filepath6");
}
