/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_
    #include "my.h"

typedef struct movement_s {
    int x;
    int y;
} movement_t;

typedef struct object_s {
    int x;
    int y;
    int status;
} object_t;

typedef struct sokoban_s {
    char **map;
    char *map_buffer;
    int input;
    int blocked;
    int nb_box;
    int file_d;
    int exit_code;
    int reset;
    int nb_player;
    int nb_target;
    char *cmap;
    struct stat statbuff;
    object_t **boxes;
    object_t player;
    movement_t mv_right;
    movement_t mv_left;
    movement_t mv_up;
    movement_t mv_down;
} sokoban_t;

#endif

//Box
sokoban_t *nb_box(sokoban_t *soko);
sokoban_t *nb_target(sokoban_t *soko);
object_t **box_position(sokoban_t *soko, object_t **boxes, int x, int y);

//Colision
void colision_handler(sokoban_t *soko, movement_t movement);
int box_asides(sokoban_t *soko, int i);
int box_style(int i_value, movement_t movement, sokoban_t *soko);
int box_colision(sokoban_t *soko, movement_t movement);

//Description
int description_0(void);
int description_84(void);

//Init
object_t **init_boxes(sokoban_t *soko);
sokoban_t *init_movement(sokoban_t *soko);
sokoban_t *init_struct(sokoban_t *soko, char *map);

//Main_Soko
sokoban_t *sokoban(sokoban_t *soko);

//Map
sokoban_t *open_map(sokoban_t *soko, char *filepath);
void showmap(sokoban_t *soko);
int map_error(sokoban_t *soko, char *filepath);
int check_map(sokoban_t *soko);
void print_last_loop(sokoban_t *soko);

//Player
sokoban_t *player_position(sokoban_t *soko);
void player_handler(sokoban_t *soko);
sokoban_t *nb_player(sokoban_t *soko);

//Status
void is_lose(sokoban_t *soko);
int is_win(sokoban_t *soko);
