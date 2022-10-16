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

int launch_soko(char **argv)
{
    sokoban_t *soko = malloc(sizeof(sokoban_t));
    int exit_code = 0;

    soko = init_struct(soko, argv[1]);
    if (soko == NULL)
        exit (my_put_error("./my_sokoban: invalid map or malloc problem\n"));
    soko->nb_box > 0 && soko->nb_target == 0 ? exit(0) : 0;
    soko->nb_box != soko->nb_target ? exit(my_put_error("Invalid map\n")) : 0;
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    soko = sokoban(soko);
    if (soko->reset == 1) {
        free_all(soko);
        endwin();
        launch_soko(argv);
    }
    exit_code = soko->exit_code;
    free_all(soko);
    return (exit_code);
}

int main(int argc, char **argv)
{

    if (argc < 2)
        return (my_put_error("./my_sokoban: missing arguments\n"));
    else if (argc == 2 && my_strcmp(argv[1], "-h"))
        return (description());
    return (launch_soko(argv));
}
