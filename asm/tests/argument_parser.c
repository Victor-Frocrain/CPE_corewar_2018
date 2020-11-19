/*
** EPITECH PROJECT, 2018
** test xyz
** File description:
** test xyz
*/

#include "my.h"
#include "asm.h"
#include <sys/stat.h>
#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <fcntl.h>

Test(Asm_parser, Bad_number_of_arguments, .init = redirect_all_std)
{
    int ac = 1;
    char *av[ac + 1];

    av[0] = "./asm";
    av[1] = NULL;
    cr_assert_(is_arguments_error(ac, av));
    cr_assert_stderr_eq_str("Error: wrong number of argument\n");
}

Test(Asm_parser, File_cant_be_openned, .init = redirect_all_std)
{
    int ac = 2;
    char *av[ac + 1];

    av[0] = "./asm";
    av[1] = "!File.s";
    av[2] = NULL;
    cr_assert_(is_arguments_error(ac, av));
    cr_assert_stderr_eq_str("Error: !File.s can't be openned\n");
}

Test(Asm_parser, Multiple_correct_file, .init = redirect_all_std)
{
    int ac = 3;
    char *av[ac + 1];
    int fd[2];

    av[0] = "./asm";
    av[1] = "existing_file.s";
    av[2] = "existing_file2.s";
    av[3] = NULL;
    fd[0] = open(av[1], O_CREAT);
    fd[1] = open(av[2], O_CREAT);
    chmod(av[1], S_IRWXU);
    chmod(av[2], S_IRWXU);
    close(fd[0]);
    close(fd[1]);
    cr_assert_(!is_arguments_error(ac, av));
    remove(av[1]);
    remove(av[2]);
}

Test(Asm_parser, Wrong_extension, .init = redirect_all_std)
{
    int ac = 2;
    char *av[ac + 1];
    int fd;

    av[0] = "./asm";
    av[1] = "Text.txt";
    av[2] = NULL;
    fd = open(av[1], O_CREAT);
    chmod(av[1], S_IRWXU);
    close(fd);
    cr_assert_(is_arguments_error(ac, av));
    cr_assert_stderr_eq_str("Error: Text.txt wrong file type\n");
    remove(av[1]);
}
