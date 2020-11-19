/*
** EPITECH PROJECT, 2019
** asm
** File description:
** filter_instruction.c
*/

#include "asm.h"
#include <criterion/criterion.h>

Test(Asm, filter_instruction_functional)
{
    char *str = strdup("  add\t 2\t 3\t\t");

    manage_instruct(str);
    cr_assert_str_eq(str, "add 2 3");
    free(str);
}

Test(Asm, filter_with_only_tab)
{
    char *str = strdup("\t\tadd\t\t2\t\t3\t\t");

    manage_instruct(str);
    cr_assert_str_eq(str, "add 2 3");
    free(str);
}

Test(Asm, filter_with_only_space)
{
    char *str = strdup("  add  2     3   ");

    manage_instruct(str);
    cr_assert_str_eq(str, "add 2 3");
    free(str);
}

Test(Asm, filter_mixed_with_comment)
{
    char *str = strdup("\t add  \t2 \t\t\t   3   # fezfozufezoufze");

    manage_instruct(str);
    cr_assert_str_eq(str, "add 2 3");
    free(str);
}

Test(Asm, filter_useless_char)
{
    char *str = strdup("hello\" \t\"\n");

    manage_instruct(str);
    cr_assert_str_eq(str, "hello\"  \"");
    free(str);
}
