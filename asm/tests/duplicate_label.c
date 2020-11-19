/*
** EPITECH PROJECT, 2019
** asm
** File description:
** duplicate_label
*/

#include "asm.h"
#include <criterion/criterion.h>

bool is_label_seen(line_t *line, char *label);

Test(Asm, label_seen)
{
    line_t line;

    line.line = "live";
    cr_assert(is_label_seen(&line, "live"));
}
