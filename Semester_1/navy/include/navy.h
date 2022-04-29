/*
** EPITECH PROJECT, 2021
** B-PSU-101-NCY-1-1-navy-antoine.khalidy
** File description:
** navy
*/

#ifndef NAVY_H_
    #define NAVY_H_

    #include <signal.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>

    #define UNUSED(x) (void)(x)

typedef struct navy_s {
    volatile int identity;
    pid_t pid;
    int started;
    int last_signal;
    int position_received;
    int x;
    int y;
} navy_t;

int description(void);

typedef struct ship {
    int length;
    char *first_square;
    char *last_square;
} ship;

extern navy_t *navy;

ship *load_ships(char *buffer);

char *open_file(char const *path);

char **load_default_map(void);

int game_loop(ship *ships);

int *get_attack_position(void);

void send_attack_position(int *coordinate);

int receive_response_of_attack(void);

int *receive_attack_position(void);

char **load_map(ship *ships);

int action_turn(char **map);

int wait_turn(char **map);

void show_map(char **map);

int checks_ships(ship *ships);

int first_player(char **argv);

void codingstyle1(char **p1_map, char **p2_map);

int codingstyle2(char **map, int i);

void codingstyle3(int i, char **map);

int check_ship_two(char *buffer);
#endif
