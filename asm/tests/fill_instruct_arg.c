/*
** EPITECH PROJECT, 2019
** asm
** File description:
** test create_instruct_arg.c
*/

#include "asm.h"
#include <criterion/criterion.h>

int count_args(char *line);

Test(Asm, count_args)
{
    char *instruct = "add r1, r1, r2";
    char *name = ".name \"zork\"";

    cr_assert_eq(count_args(instruct), 3);
    cr_assert_eq(count_args(name), 1);
}

Test(Asm, fill_instruct)
{
    line_t *line = malloc(sizeof(line_t));

    line->line = my_strdup("add r1,r2, r3");
    line->nb_arg = 0;
    cr_assert(!fill_instruct_arg(line));
    cr_assert_eq(line->nb_arg, 3);
    cr_assert_str_eq(line->line, "add");
    cr_assert_str_eq(line->args[0], "r1");
    cr_assert_str_eq(line->args[1], "r2");
    cr_assert_str_eq(line->args[2], "r3");
    free(line->line);
    free(line->args);
    free(line);
}

Test(Asm, fill_dotname)
{
    line_t *line = malloc(sizeof(line_t));

    line->line = my_strdup(".name \"zork\"");
    line->nb_arg = 0;
    cr_assert(!fill_instruct_arg(line));
    cr_assert_eq(line->nb_arg, 1);
    cr_assert_str_eq(line->line, ".name");
    cr_assert_str_eq(line->args[0], "\"zork\"");
    free(line->line);
    free(line->args);
    free(line);
}
