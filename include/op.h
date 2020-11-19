/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** op.h
*/

#ifndef _OP_H_
#define _OP_H_

#define MEM_SIZE (6*1024)
#define IDX_MOD (512)
#define MAX_ARGS_NUMBER (4) /* this may not be changed 2^*IND_SIZE */

#define COMMENT_CHAR ('#')
#define LABEL_CHAR (':')
#define DIRECT_CHAR ('%')
#define SEPARATOR_CHAR (',')

#define LABEL_CHARS ("abcdefghijklmnopqrstuvwxyz_0123456789")

#define NAME_CMD_STRING (".name")
#define COMMENT_CMD_STRING (".comment")

/*
** regs
*/

#define REG_NUMBER (16) /* r1 <--> rx */

/*
**
*/

typedef char args_type_t;

#define T_REG (0b0001)
#define T_DIR (0b0010)
#define T_IND (0b0100)
#define T_LAB (0b1000)

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
}op_t;

/*
** size (in bytes)
*/

#define IND_SIZE (2)
#define DIR_SIZE (4)
#define REG_SIZE (DIR_SIZE)

/*
** op_tab
*/

extern op_t op_tab[];

/*
** header
*/
#define PROG_NAME_LENGTH (128)
#define COMMENT_LENGTH (2048)

#define COREWAR_EXEC_MAGIC (0xea83f3)
typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
}header_t;

/*
** live
*/

#define CYCLE_TO_DIE (1536) /* number of cycle before beig declared dead */
#define CYCLE_DELTA (5)
#define NBR_LIVE (40)

#endif /* _OP_H*/
