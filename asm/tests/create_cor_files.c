/*
** EPITECH PROJECT, 2019
** asm_tests
** File description:
** create_cor_file
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <stdio.h>

Test(Asm_create_file, New_name_size)
{
    char *file_name = "Test.s";
    int size_expected = my_strlen("Test") + my_strlen(".cor") + 1;

    cr_assert_eq(get_cor_name_size(file_name), size_expected);
}

Test(Asm_create_file, Create_file_desc)
{
    char *file_name = "Test.s";
    int fd = create_cor_file(file_name);

    cr_assert(fd > 0);
    close(fd);
    remove("Test.cor");
}
