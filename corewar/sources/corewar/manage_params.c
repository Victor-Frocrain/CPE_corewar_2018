/*
** EPITECH PROJECT, 2019
** manage_params
** File description:
** manage_params
*/

#include "corewar.h"

void fill_address(machine_t *machine)
{
    int diff = 0;
    int address = 0;

    if ((*machine).total - 1 > 0)
        diff = MEM_SIZE / (*machine).total;
    for (int i = 0; i < (*machine).total; i++) {
        if ((*machine).champion[i]->process->pc < 0) {
            (*machine).champion[i]->process->pc = address;
            address += diff;
        }
    }
}

void fill_number(machine_t *machine)
{
    int max_number = 0;

    for (int i = 0; i < (*machine).total; i++)
        if ((*machine).champion[i]->number > max_number)
            max_number = (*machine).champion[i]->number;
    for (int i = 0; i < (*machine).total; i++)
        if ((*machine).champion[i]->number < 0) {
            (*machine).champion[i]->number = max_number + 1;
            max_number++;
        }
}

bool is_bytecode_superimposed(champion_t *champion1, champion_t *champion2)
{
    int i = champion1->process->pc;

    if (champion1 == champion2)
        return (false);
    for (int j = 0; j < champion1->header->prog_size; j++) {
        if (i == champion2->process->pc)
            return (true);
        add_pc(&i, 1);
    }
    return (false);
}

bool fill_champ_value_uninitialized(machine_t *machine)
{
    bool is_error = false;
    int i = 0;
    int j = 0;

    fill_number(machine);
    fill_address(machine);
    for (; !is_error && i < (*machine).total; !is_error ? i++ : i) {
        for (j = 0; !is_error && j < (*machine).total; !is_error ? j++ : j)
            is_error = is_bytecode_superimposed((*machine).champion[i], \
(*machine).champion[j]);
        if (is_number_used((*machine).champion, (*machine).total))
            return (true);
    }
    if (is_error) {
        print_error_color(C_MAGENTA, "Error: \033[1;34m");
        my_puterror((*machine).champion[i]->header->prog_name);
        print_error_color(C_MAGENTA, " and \033[1;34m");
        my_puterror((*machine).champion[j]->header->prog_name);
        print_error_color(C_MAGENTA, " are superimposed\n");
    }
    return (is_error);
}
