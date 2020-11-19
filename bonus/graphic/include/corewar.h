/*
** EPITECH PROJECT, 2019
** Corewar
** File description:
** corewar.h
*/

#ifndef _COREWAR_H
#define _COREWAR_H

#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "my.h"
#include "my_printf.h"
#include "get_next_line.h"
#include "op.h"
#include "graphic.h"


#define REST (round(sqrtf(MEM_SIZE)) - \
(MEM_SIZE - (round(sqrtf(MEM_SIZE)) * round(sqrtf(MEM_SIZE)))) + 1)
#define TEXT (10)
#define BUTTONS (7)
#define VOLUME (2)
#define MUSIC (3)
#define BACK (9)
#define PARTICULES (500)
#define SPARK (20)
#define NB_FIRE (20)
#define FIRE (1000)

#define DIRECT (0b10)
#define REGISTER (0b01)
#define INDIRECT (0b11)

typedef struct object_s {
    sfRectangleShape *shape;
    sfColor color;
    sfVector2f pos;
    sfVector2f size;
    sfText *text;
} object_t;

typedef struct image_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f size;
    float speed;
} image_t;

typedef struct indic_s {
    sfText *text[TEXT];
    sfFont *font;
} indic_t;

typedef struct scene_s {
    bool menu;
    bool settings;
    bool game;
    bool begin;
    bool over;
    bool credits;
} scene_t;

typedef struct particule_s {
    sfUint8 pixel[4];
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f dir;
    sfClock *alive;
    int life;
    int nb_alive;
} particule_t;

typedef struct graphic_s {
    sfVideoMode video;
    sfRenderWindow *window;
    sfEvent event;
    sfMusic *music[MUSIC];
    object_t cases[MEM_SIZE];
    image_t buttons[BUTTONS];
    image_t volume[VOLUME];
    image_t back[BACK];
    particule_t stuff[PARTICULES];
    particule_t spark[SPARK];
    particule_t fire[NB_FIRE][FIRE];
    indic_t indic;
    scene_t scene;
    sfClock *clock;
    int limit_round;
    bool is_clicked;
    bool pause;
} graphic_t;

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
    sfColor color;
    char *file;
    int nb_live;
    int nb_process;
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
    graphic_t *graphic;
    int cycle_to_death;
    int cycle;
    int dump;
    int total;
}machine_t;

#include "function.h"

/*
** graphic
*/
void begin_game(graphic_t *graphic, sfVector2f pos);
int graphic_loop(machine_t *machine);
char *my_getstr(int nb);
void change_colors(graphic_t *graphic, champion_t *champion, int pc);
int count_winner(machine_t machine);
bool is_mem_pos_pc(machine_t *machine, int pos);

/*
** graphic init graphic
*/
void ini_backs(graphic_t *graphic);
bool ini_objects(graphic_t *graphic, object_t *empty);
void ini_spark(graphic_t *graphic);
void ini_textures(graphic_t *graphic);
bool ini_graphic(graphic_t *graphic, object_t *empty);
void ini_light(graphic_t *graphic);
void ini_stuff(graphic_t *graphic);
bool ini_images(graphic_t *graphic);
bool ini_sounds(graphic_t *graphic);
bool ini_text(graphic_t *graphic);
void init_fireworks(graphic_t *graphic);
void fill_fire(graphic_t *graphic, int i);

/*
** graphic display funtion
*/
void display_elements(graphic_t *graphic, object_t *empty, machine_t *machine);
void display_over(graphic_t *graphic);
void display_settings(graphic_t *graphic);
void display_menu(graphic_t *graphic);
void display_credits(graphic_t *graphic);
void display_info(machine_t *machine);

/*
** graphic update function
*/
void update_time(graphic_t *graphic);
void update_lines(graphic_t *graphic);
void update_light(graphic_t *graphic);
void update_stuff(graphic_t *graphic);
void update_pixel_sprite(particule_t *stuff);
void update_spark(graphic_t *graphic);
void update_text(sfText *text, char *str, int nb);

/*
** graphic manage function
*/
bool manage_scene(graphic_t *graphic, object_t *empty, machine_t *machine);
void manage_buttons(graphic_t *graphic, int min, int max);
void manage_volume(graphic_t *graphic);
void manage_mute(graphic_t *graphic);
void manage_over(machine_t machine);
void manage_pause(graphic_t *graphic);
void manage_fireworks(graphic_t *graphic);

/*
** graphic destroy function
*/
void destroy_all(graphic_t *graphic, object_t *empty);

/*
** corewar
*/
void print_int_in_map(int pc, machine_t *machine, int nb, champion_t *champion);
bool is_instruct_index(char c);
void dump(machine_t machine);
bool is_instruct_correct(const instruct_t *instruct);
int get_value(int i, process_t *process, machine_t *machine);
int get_value_from_ind(int pc, machine_t *machine);
bool check_if_usage(int ac, char **av);
int reverse_int(int nb);
int reverse_short(int nb);
void add_pc(int *pc, int to_add);
bool is_reg_outside(int nb);
int get_val(char *arg, bool is_short);
int load_data(process_t *process, machine_t *machine, int to_add);

/*
** Game loop
*/
void game_loop(machine_t *machine, graphic_t *graphic, object_t *empty);
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
