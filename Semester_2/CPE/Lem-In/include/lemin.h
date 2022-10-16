/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** lemin
*/

#ifndef LEMIN_H_
    #define LEMIN_H_
    #include "my.h"

typedef struct tmp_s {
    int first;
    int exited;
} tmp_t;

typedef enum type_s {
    START,
    END,
    NORMAL
} type_t;

typedef struct tunnels_s {
    struct rooms_s *dest;
    struct tunnels_s *next;
} tunnels_t;

typedef struct rooms_s {
    char *id;
    int dist;
    int x;
    int y;
    type_t type;
    struct tunnels_s *tunnel;
    struct rooms_s *next;
    int ants;
    int visited;
} rooms_t;

typedef struct ant_s {
    char *name;
    rooms_t *room;
    struct ant_s *next;
} ant_t;

typedef struct lemin_s {
    int nb_ants;
    char *c_map;
    char **tun;
    char **d_map;
    rooms_t *alg;
    rooms_t *start;
    rooms_t *end;
    ant_t *ants;
    ant_t *ants_tmp;
    tunnels_t *tunnels;
    rooms_t *nearest_room;
    tmp_t tmp;
} lemin_t;

#endif

int parser(lemin_t *g);
int get_data(lemin_t *g);
int check_nbr_arg(char *str, char sep);
int get_nbr_ants(lemin_t *g);
int my_is_num(char *str, char sep);
int get_room(lemin_t *g);
void show_room(lemin_t *g);
void print_path(lemin_t *g, char *steps);
int init_tunnels(lemin_t *g, int i);
int algo(lemin_t *g);
rooms_t *get_start(lemin_t *g);
rooms_t *get_end(lemin_t *g);
void free_all(lemin_t *g);
int get_x(char *str);
int get_y(char *str);
tunnels_t *add_link(tunnels_t *tun, rooms_t *g, char *id2);
lemin_t *tunnel_loop(lemin_t *g);
char **nearest_cond(lemin_t *g, char **steps);
char **ants_loop(lemin_t *g, char **steps);
int error_mngt(char **str);
int error_ants(char *str);
int error_rooms(char **str);
int check_room(lemin_t *g, char *id);
int check_start_end(lemin_t *g, type_t type);
int check_repeat_name(lemin_t *g);
