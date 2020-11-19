/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** function.h
*/

#ifndef _FUNCTION_H
#define _FUNCTION_H

#include "corewar.h"

typedef struct func_s {
    void (*func)(machine_t *machine, champion_t *champion);
}func_t;

void f_live(machine_t *machine, champion_t *champion);
void f_ld(machine_t *machine, champion_t *champion);
void f_st(machine_t *machine, champion_t *champion);
void f_add(machine_t *machine, champion_t *champion);
void f_sub(machine_t *machine, champion_t *champion);
void f_and(machine_t *machine, champion_t *champion);
void f_or(machine_t *machine, champion_t *champion);
void f_xor(machine_t *machine, champion_t *champion);
void f_zjmp(machine_t *machine, champion_t *champion);
void f_ldi(machine_t *machine, champion_t *champion);
void f_sti(machine_t *machine, champion_t *champion);
void f_fork(machine_t *machine, champion_t *champion);
void f_lld(machine_t *machine, champion_t *champion);
void f_lldi(machine_t *machine, champion_t *champion);
void f_lfork(machine_t *machine, champion_t *champion);
void f_aff(machine_t *machine, champion_t *champion);

extern func_t func[16];

#endif /* _FUNCTION_H */
