/*
** EPITECH PROJECT, 2019
** asm
** File description:
** functionnal.c
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char *read_file(char *filepath);

Test(Asm, functional)
{
    int ac = 2;
    char *av[ac + 1];
    char *res;
    char *expected;

    av[0] = "./asm";
    av[1] = "tests/example.s";
    av[2] = NULL;
    cr_assert_eq(read_files(ac, av), MY_SUCCESS);
    res = read_file("tests/example.cor");
    expected = read_file("tests/res_func.cor");
    cr_expect_str_eq(res, expected);
    free(res);
    free(expected);
    remove("test/example.cor");
}

Test(Asm, empty_file, .init = redirect_all_std)
{
    int ac = 2;
    char *av[] = {"./asm", "tests/empty_file.s", NULL};

    cr_assert_eq(read_files(ac, av), MY_ERROR);
    cr_assert_stderr_eq_str("\033[1;35mEmpty file\n\033[0m");
}
