/*
** EPITECH PROJECT, 2019
** asm
** File description:
** test converting int to byte code
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Asm, convert_int_magic, .init = redirect_all_std)
{
    int magic = reverse_int(COREWAR_EXEC_MAGIC);

    cr_assert_eq((magic & 0xFF000000) >> (4 * 6), 0xF3);
    cr_assert_eq((magic & 0x00FF0000) >> (4 * 4), 0x83);
    cr_assert_eq((magic & 0x0000FF00) >> (4 * 2), 0xea);
    cr_assert_eq(magic & 0x000000FF, 0x00);
}

Test(Asm, convert_short_magic, .init = redirect_all_std)
{
    short res = reverse_short(0x12FF);

    cr_assert_eq((res & 0x0FF00) >> 8, 0xFF);
    cr_assert_eq(res & 0x00FF, 0x12);
}
