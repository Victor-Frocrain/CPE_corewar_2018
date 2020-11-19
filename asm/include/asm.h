/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** asm.h
*/

#ifndef _ASM_H
#define _ASM_H

#include "my.h"
#include "my_printf.h"
#include "get_next_line.h"
#include "op.h"

typedef struct line_s {
    char *line;
    int nb_line;
    char **args;
    int nb_arg;
    struct line_s *next;
}line_t;

typedef struct data_s {
    line_t *line;
    header_t header;
    bool is_endian;
}data_t;

char **str_to_word(char *str, char c);
char **open_map(char *filepath);
char *my_getstr(int nb);

/*
** Manage instruct
*/
void manage_instruct(char *line);
bool fill_instruct_arg(line_t *line);
bool is_useless_char(char *str, int i);
void remove_useless_char(char *str);
int reverse_int(int nb);
int reverse_short(int nb);
void compile_and_write(char *str, bool *is_error, data_t *data);
void write_header(int to_write, data_t *data);
void write_prog(int to_write, line_t *line, data_t data);
void write_type(int to_write, line_t *line);
void write_arg(int to_write, line_t *line, char *str, data_t data);
int calc_label_dist(char *str, line_t *line, data_t data);

/*
** Manage operator
*/
bool is_instructs_correct(data_t data, int *prog_size);
bool is_instruct_correct(line_t *line, data_t data, int *prog_size);
bool is_args_correct(line_t *line, op_t op, data_t data, int *prog_size);
bool is_arg_correct(char *arg, args_type_t type, data_t data, int *prog_size);
bool is_register(char *arg, bool *is_error, int *prog_size);
bool is_direct(char *arg, line_t *line, bool *is_error, int *prog_size);
bool is_indirect(char *arg, line_t *line, bool *is_error, int *prog_size);
bool is_label(char *arg, line_t *line, bool *is_error);

/*
** Read files
*/
int read_files(int ac, char **av);
void read_a_file(char *str, bool *is_error, data_t *data);
data_t ini_data(void);
bool manage_dot(line_t *line, char *ref, int length);
void get_dotname(line_t *line, char *str);
bool is_double_quote(char *line, int nb_line, int *size);
bool is_duplicate_label(line_t *line);
bool is_instruct_index(char *str);

/*
** Create file
*/
int get_cor_name_size(char *file_name);
int create_cor_file(char *file_name);

/*
** Parser
*/
bool is_arguments_error(int ac, char **av);
void print_file_error(char *file, char *error);
void print_error(char *str);
void print_error_color(char *color, char *str, bool is_bold);
void print_line_error_color(char *str, int nb_line);

/*
** Manage color
*/
#define C_RED ("31")
#define C_GREEN ("32")
#define C_YELLOW ("33")
#define C_BLUE ("34")
#define C_MAGENTA ("35")
#define C_CYAN ("36")

/*
** Destroy
*/
void destroy_datas(int ac, data_t *data);


#endif /* _ASM_H */
