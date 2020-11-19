/*
** EPITECH PROJECT, 2019
** open_file
** File description:
** open_file
*/

#include "corewar.h"
#include <fcntl.h>

bool read_file(int fd, champion_t *champions, int length, bool is_header)
{
    int red = 0;

    if (is_header)
        red = read(fd, champions->header, length);
    else
        red = read(fd, champions->file, length);
    if (red != length) {
        print_error_color(C_MAGENTA, "Error: unexpected read size\n");
        return (true);
    }
    return (false);
}

bool fill_header(int fd, champion_t *champions)
{
    bool is_error = false;

    is_error = read_file(fd, champions, sizeof(header_t), true);
    if (!is_error) {
        champions->header->magic = reverse_int(champions->header->magic);
        champions->header->prog_size = \
reverse_int(champions->header->prog_size);
        champions->file = malloc(sizeof(char) * \
(champions->header->prog_size + 1));
        is_error = !champions->file;
        if (!is_error)
            is_error = read_file(fd, champions, champions->header->prog_size, \
false);
    }
    return (is_error);
}

void fill_champion(champion_t *champion, bool is_error)
{
    if (!is_error) {
        champion->process->pc = -1;
        champion->process->carry = false;
        champion->process->cumu_cycle = 1;
        champion->process->next = NULL;
        champion->first_process = champion->process;
        champion->number = -1;
        champion->was_living = true;
        champion->is_alive = true;
        champion->process->instruct->code = -1;
        for (int i = 0; i < 3; i++)
            my_memset(champion->process->instruct->arg[i], 0, 5);
        for (int i = 0; i < REG_NUMBER; i++)
            champion->process->registers[i] = 0;
    }
}

champion_t *ini_champion(char *filepath)
{
    champion_t *champion = malloc(sizeof(champion_t));
    bool is_error = !champion;

    if (!is_error) {
        champion->header = malloc(sizeof(header_t));
        champion->process = malloc(sizeof(process_t));
        champion->fd = open(filepath, O_RDONLY);
        is_error = !champion->header || !champion->process;
        if (champion->fd < 0 || is_error) {
            print_error_color(C_MAGENTA, "Error: the file can't be red\n");
            free(champion);
            return (NULL);
        } else {
            champion->process->instruct = malloc(sizeof(instruct_t));
            is_error = !champion->process->instruct;
            fill_champion(champion, is_error);
        }
    }
    return (is_error ? NULL : champion);
}

bool open_file(char **av, machine_t *machine, int old_core, int new_core)
{
    bool is_error = false;
    int pos = (*machine).total;

    (*machine).total++;
    (*machine).champion[pos] = ini_champion(av[new_core]);
    is_error = !(*machine).champion[pos];
    for (; !is_error && old_core != new_core; old_core += 2)
        is_error = identify_flags(av, machine, old_core, new_core);
    return ((!is_error) ? fill_header((*machine).champion[pos]->fd, \
(*machine).champion[pos]) : true);
}
