/*
** EPITECH PROJECT, 2019
** asm
** File description:
** test manage name
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Asm, Manage_quote_not_enough, .init = redirect_all_std)
{
    char *line = ".name \"zork";
    int size = 0;

    cr_assert(!is_double_quote(line, 1, &size));
    cr_assert_stderr_eq_str("\033[1;35mLine 1: missing quotes\n");
}

Test(Asm, Manage_quote_too_much, .init = redirect_all_std)
{
    char *line = ".name \"zork\"\"";
    int size = 0;

    cr_assert(!is_double_quote(line, 1, &size));
    cr_assert_stderr_eq_str("\033[1;35mLine 1: too much quotes\n");
}

Test(Asm, Manage_get_dotname)
{
    line_t *line = malloc(sizeof(line_t));
    char **arg = malloc(sizeof(char *) * 2);
    char *name = "\"zork\"";
    char *str = malloc(sizeof(char) * 10);

    arg[0] = name;
    arg[1] = NULL;
    line->args = arg;
    memset(str, 0, 9);
    get_dotname(line, str);
    cr_assert_str_eq(str, "zork");
    free(str);
    free(arg);
    free(line);
}

Test(Asm, Functionnal_manage_name, .init = redirect_all_std)
{
    line_t line;
    char *args[] = {"\"Hello this is a too long name\"", NULL};

    line.line = ".name";
    line.args = args;
    line.nb_line = 1;
    cr_assert(manage_dot(&line, NULL, 1));
    cr_assert_stderr_eq_str("\033[1;35mLine 1: .name is too long\n");
}

Test(Asm, Functionnal_manage_dot_error, .init = redirect_all_std)
{
    line_t *line = malloc(sizeof(line_t));
    char *name = ".name \"zork\"\"";
    char *str = my_strdup("000000000000");

    line->args = malloc(sizeof(char *) * 2);
    line->args[0] = name;
    line->args[1] = NULL;
    line->nb_arg = 1;
    line->nb_line = 1;
    cr_assert(manage_dot(line, str, PROG_NAME_LENGTH));
    cr_assert_stderr_eq_str("\033[1;35mLine 1: too much quotes\n");
    free(line->args);
    free(line);
}
