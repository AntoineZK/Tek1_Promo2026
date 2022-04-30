/*
** EPITECH PROJECT, 2021
** B-PSU-101-NCY-1-1-navy-antoine.khalidy
** File description:
** navy_game
*/

#include "../include/my.h"
#include "../include/navy.h"

int *receive_attack_position(void)
{
    int *coordinate = malloc(sizeof(int) * 2);
    while (!navy->position_received) {
        usleep(10000);
    }
    coordinate[0] = navy->x - 1;
    coordinate[1] = navy->y - 1;
    navy->x = 0;
    navy->y = 0;
    navy->position_received = 0;
    return (coordinate);

}

int receive_response_of_attack(void)
{
    while (!navy->x && !navy->y)
        navy->last_signal = 0;
    if (!navy->x) {
        navy->y = 0;
        return (1);
    } else {
        navy->x = 0;
        return (0);
    }
}

void send_attack_position(int *coordinate)
{
    for (int i = 0; i < coordinate[0] + 1; i++) {
        kill(navy->pid, SIGUSR1);
        usleep(10000);
    }
    for (int i = 0; i < coordinate[1] + 1; i++) {
        kill(navy->pid, SIGUSR2);
        usleep(10000);
    }
    kill(navy->pid, SIGUSR1);
}

int *get_attack_position(void)
{
    char *line = NULL;
    size_t len = 0;
    int *coordinate = malloc(sizeof(int) * 2);
    while (1) {
        my_putstr("\nattack: ");
        getline(&line, &len, stdin);
        if (line[0] <= 'H' && line[0] >= 'A' && line[1] >= '1' &&
        line[1] <= '8')
            break;
        else
            my_putstr("wrong position");
    }
    coordinate[0] = line[0] - 'A';
    coordinate[1] = line[1] - '1';
    free(line);
    return (coordinate);
}

int game_loop(ship *ships)
{
    char **p1_map = load_map(ships);
    char **p2_map = load_default_map();
    int turn = navy->identity == 10;
    while (1) {
        if (!navy->started || (turn && navy->identity == 10) ||
        (!turn && navy->identity == 12))
            codingstyle1(p1_map, p2_map);
        if ((!navy->started) && !turn) {
            my_putstr("\nI won\n\n");
            return (0);
        } else if (!navy->started && turn) {
            my_putstr("\nEnemy won\n\n");
            return (1);
        }
        if (turn)
            action_turn(p2_map);
        else
            wait_turn(p1_map);
        turn = (turn - 1) * -1;
    }
}
