/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** disasm.h
*/

#ifndef _DISASM_H
#define _DISASM_H

#include "my.h"
#include "my_printf.h"
#include "get_next_line.h"
#include "op.h"

#define REGISTER (0b01)
#define DIRECT (0b10)
#define INDIRECT (0b11)

typedef struct instruct_s {
    short code;
    short nb_arg;
    char arg[3][4 + 1];
    short mask[3];
}instruct_t;

char **str_to_word(char *str, char c);
char **open_map(char *filepath);
char *my_getstr(int nb);
int reverse_int(int nb);
int reverse_short(int nb);

/*
** Disasm
*/
int disasm(int ac, char **av);
int create_asm_file(char *file_name);
void write_asm(int fd, char *file, header_t header);
void fill_instruct(instruct_t *instruct, char *file);
bool is_instruct_index(char c);

/*
** Parser
*/
bool parser(int ac, char **av);

/*
** Manage color
*/
#define C_RED ("31")
#define C_GREEN ("32")
#define C_YELLOW ("33")
#define C_BLUE ("34")
#define C_MAGENTA ("35")
#define C_CYAN ("36")
void print_error_color(char *color, char *str, bool is_bold);

#endif /* _ASM_H */
