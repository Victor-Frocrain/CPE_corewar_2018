/*
** EPITECH PROJECT, 2019
** asm
** File description:
** index
*/

#include "asm.h"
#include <criterion/criterion.h>

Test(Asm, index)
{
    cr_assert(is_instruct_index("ldi"));
    cr_assert(is_instruct_index("sti"));
    cr_assert(is_instruct_index("zjmp"));
    cr_assert(is_instruct_index("fork"));
    cr_assert(is_instruct_index("lfork"));
    cr_assert(is_instruct_index("lldi"));
    cr_assert(!is_instruct_index("and"));
}
