/*
** EPITECH PROJECT, 2019
** Corewar
** File description:
** corewar.h
*/

#ifndef _COREWAR_H
#define _COREWAR_H

#include "my.h"
#include "my_printf.h"
#include "get_next_line.h"
#include "op.h"

#define DIRECT (0b10)
#define REGISTER (0b01)
#define INDIRECT (0b11)

typedef struct instruct_s {
    short code;
    short nb_arg;
    char arg[3][4 + 1];
    short mask[3];
}instruct_t;

typedef struct process_s {
    int pc;
    bool carry;
    int cumu_cycle;
    int registers[REG_NUMBER];
    instruct_t *instruct;
    struct process_s *next;
}process_t;

typedef struct champion_s {
    header_t *header;
    int fd;
    char *file;
    bool was_living;
    bool is_alive;
    process_t *first_process;
    process_t *process;
    int number;
}champion_t;

typedef struct machine_s {
    champion_t *champion[MAX_ARGS_NUMBER];
    char map[MEM_SIZE];
    int nb_live;
    int cycle_to_death;
    int cycle;
    int dump;
    int total;
}machine_t;

#include "function.h"

/*
** Corewar
*/
void print_int_in_map(int pc, machine_t *machine, int nb);
bool is_instruct_index(char c);
void dump(machine_t machine);
bool is_instruct_correct(const instruct_t *instruct);
int get_value(int i, process_t *process, machine_t *machine);
int get_value_from_ind(int pc, machine_t *machine);
bool check_if_usage(int ac, char **av);
int reverse_int(int nb);
int reverse_short(int nb);
void add_pc(int *pc, int nb);
bool is_reg_outside(int nb);
int get_val(char *arg, bool is_short);
int load_data(process_t *process, machine_t *machine, int to_add);

/*
** Game loop
*/
void game_loop(machine_t *machine);
bool is_less_than_2_alive(machine_t machine);
void display_winner(machine_t machine);
void fill_instruct(instruct_t *instruct, machine_t machine, int pc);

/*
** Init
*/
int corewar(int ac, char **av);
bool open_file(char **av, machine_t *machine, int old_core, int new_core);
void fill_address(machine_t *machine);
bool fill_champ_value_uninitialized(machine_t *machine);
void add_champion_code_on_map(machine_t *machine);
bool identify_flags(char **av, machine_t *machine, int old_core, int new_core);

/*
** Parser
*/
bool parser(char **av, machine_t *machine);
bool check_value(char *str);
bool fill_dump(char **av, int old_core, machine_t *machine);
bool is_number_used(champion_t **champion, int total);

/*
** Manage color
*/
void print_error_color(char *color, char *str);
#define C_RED ("31")
#define C_GREEN ("32")
#define C_YELLOW ("33")
#define C_BLUE ("34")
#define C_MAGENTA ("35")
#define C_CYAN ("36")

/*
** Destroy ressources
*/
void destroy_ressources(machine_t machine);
#endif /* _COREWAR_H */
