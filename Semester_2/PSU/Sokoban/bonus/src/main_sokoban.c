/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-mysokoban-antoine.khalidy
** File description:
** main_sokoban
*/

#include "../include/sokoban.h"

sokoban_t *sokoban(sokoban_t *soko)
{
    while (1) {
        erase();
        showmap(soko);
        move(soko->player.y, soko->player.x);
        printw("P");
        refresh();
        soko->input = getch();
        if (soko->input == ' ') {
            soko->reset = 1;
            break;
        }
        player_handler(soko);
        if (is_win(soko)) {
            soko->exit_code = 0;
            break;
        } else if (soko->blocked)
            break;
    }
    print_last_loop(soko);
    return (soko);
}

int launch_soko(char *map)
{
    sokoban_t *soko = malloc(sizeof(sokoban_t));

    soko = init_struct(soko, map);
    if (soko == NULL)
        exit (my_put_error("./my_sokoban: invalid map or malloc problem\n"));
    soko->nb_box > 0 && soko->nb_target == 0 ? exit(0) : 0;
    soko->nb_box != soko->nb_target ? exit(my_put_error("Invalid map\n")) : 0;
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    soko = sokoban(soko);
    if (soko->reset == 1) {
        free(soko);
        endwin();
        launch_soko(map);
    }
    return (soko->exit_code);
}

int launch_bonus(char *input)
{
    int exit_code = 0;

    exit_code = launch_soko(input);

    return (exit_code);
}
