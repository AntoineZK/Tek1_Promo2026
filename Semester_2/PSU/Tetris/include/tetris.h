/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #include "../include/my.h"
    #include "ncurses.h"
    #include <dirent.h>
    #include <time.h>

typedef enum movement_s {
    RIGHT,
    LEFT,
    DROP,
    UP,
} movement_t;

typedef enum int_dstar_s {
    WALL,
    SPACE,
} int_dstar_t;

typedef struct lk_list_s {
    char **tetrimino;
    char *id;
    int color;
    int x;
    int y;
    bool status;
    int pos_x;
    int pos_y;
    struct lk_list_s *next;
} lk_list;

typedef struct tetris_s {
    bool help;
    int level;
    int key_left;
    int key_right;
    int key_drop;
    int key_turn;
    int key_quit;
    int key_pause;
    int col;
    int line;
    bool hide;
    bool debug;
    char **map;
    int del_line;
    int term_col;
    int term_line;
    lk_list *piece;
    char **panel;
    char **next;
    int **color_map;
    int score;
    int seconds;
    int minutes;
    int highscore;
    int time;
    int input;
    int is_able;
    bool can_continue;
    int nb_col;
    int nb_l;
    int y_center;
    int x_center;
    int true_x;
    int true_y;
    float *speed_fall;
} tetris_t;

#endif

void full_map(tetris_t *g);
void free_all(tetris_t *g);
lk_list *lk_list_add(lk_list *list, char **tet, char *id, char *line);
void print_map(tetris_t *g);
int description(void);
void init_struct(tetris_t *g);
int debug(tetris_t *g, char **av, char *path);
char *open_file(char *path);
char *remove_space(char *buf);
void my_strcpyto(char *str, char *cpy, int len);
char **parse(char *str, char separator);
void show_list(lk_list *list);
int add_param(tetris_t *g, char **av, int i);
int check_flag(char *arg, char *small, char *full);
int my_isnum(char *num);
int get_level(tetris_t *g, char **av, int i);
int get_debug(tetris_t *g, char **av, int i);
int get_without_next(tetris_t *g, char **av, int i);
int get_map_size(tetris_t *g, char **av, int i);
int get_pause_key(tetris_t *g, char **av, int i);
int get_quit_key(tetris_t *g, char **av, int i);
int get_left_key(tetris_t *g, char **av, int i);
int get_right_key(tetris_t *g, char **av, int i);
int get_turn_key(tetris_t *g, char **av, int i);
int get_drop_key(tetris_t *g, char **av, int i);
int show_debug(tetris_t *g);
int list_len(lk_list *list);
int get_param(tetris_t *g, char **av);
int check_ext(char *str);
int get_color_code(char *str);
void my_shownbr(int nb);
int check_file(tetris_t *g, char *topath, char *name);
void print_map_panel(tetris_t *g);
void full_panel(tetris_t *g);
void apply_color(tetris_t *g, int x, int y);
void replace_int_dstar(tetris_t *g, int x, int y);
void create_color(void);
void collision_handler(tetris_t *g, int movement);
clock_t input_handler(tetris_t *g, clock_t soft_drop);
void print_tetriminos(tetris_t *g);
clock_t movement_handler(tetris_t *g, clock_t soft_drop);
void place_in_map(tetris_t *g);
int able_to_move(int movement, tetris_t *g);
void full_next(tetris_t *g);
void print_next(tetris_t *g);
void remove_line(tetris_t *g);
void score_handler(tetris_t *g);
void print_info(tetris_t *g, int time);
int nb_line(char *map);
int nb_column(char *map);
int nb_line_tetriminos(char **to_count);
int highscore_get(tetris_t *g);
int highscore_set(tetris_t *g);
int max_len_line(tetris_t *g);
char **tetris_error(char *filepath);
int show_help(char **argv);
int list_len(lk_list *list);
void restart(tetris_t *g, char *path);
void rotate(tetris_t *g);
