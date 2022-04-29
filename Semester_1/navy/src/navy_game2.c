/*
** EPITECH PROJECT, 2021
** B-PSU-101-NCY-1-1-navy-antoine.khalidy
** File description:
** navy_game2
*/

#include "../include/my.h"
#include "../include/navy.h"

int check_lost(char **map)
{
    for (int i = 0; i < 8; i++) {
        if (codingstyle2(map, i) == 0)
            return (0);
    }
    return (1);
}

int action_turn(char **map)
{
    int *coordinate = get_attack_position();
    send_attack_position(coordinate);
    int response = receive_response_of_attack();
    my_putchar(coordinate[0] + 'A');
    my_putchar(coordinate[1] + '1');
    if (response) {
        my_putstr(": hit\n");
        map[coordinate[1]][coordinate[0]] = 'x';
        usleep(500);
        navy->started = !receive_response_of_attack();
    } else {
        my_putstr(": missed\n");
        map[coordinate[1]][coordinate[0]] = 'o';
    }
    return (1);
}

int wait_turn(char **map)
{
    my_putstr("\nwaiting for enemy's attack...");
    int *coordinate = receive_attack_position();
    my_putchar('\n');
    my_putchar(coordinate[0] + 'A');
    my_putchar(coordinate[1] + '1');
    if (map[coordinate[1]][coordinate[0]] != '.') {
        map[coordinate[1]][coordinate[0]] = 'x';
        my_putstr(": hit\n");
        kill(navy->pid, SIGUSR2);
        usleep(10000);
        if (check_lost(map)) {
            navy->started = 0;
            kill(navy->pid, SIGUSR2);
        }
    } else {
        map[coordinate[1]][coordinate[0]] = 'o';
        my_putstr(": missed\n");
    }
    kill(navy->pid, SIGUSR1);
    return (1);
}
