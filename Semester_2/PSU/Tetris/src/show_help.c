/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** show_help
*/

#include "tetris.h"

static void show_help_two(void)
{
    my_putstr("  -q --key-quit={K}    QUIT the game using the K key (def: ‘");
    my_putstr("q’ key)\n");
    my_putstr("  -p --key-pause={K}   PAUSE/RESTART the game using the K ke");
    my_putstr("y (def: space bar)\n");
    my_putstr("  --map-size={row,col} Set the numbers of rows and columns o");
    my_putstr("f the map (def: 20,10)\n");
    my_putstr("  -w --without-next    Hide next tetrimino (def: false)\n");
    my_putstr("  -D --debug           Debug mode (def: false)\n");
}

int show_help(char **argv)
{
    my_putstr("Usage: ");
    my_putstr(argv[0]);
    my_putstr(" [options]\n");
    my_putstr("Options:");
    my_putstr("  --help               Display this help\n");
    my_putstr("  -L --level={num}     Start Tetris at level num (def: 1)\n");
    my_putstr("  -l --key-left={K}    Move the tetrimino LEFT using the K ");
    my_putstr("key def: left arrow)\n");
    my_putstr("  -r --key-right={K}   Move the tetrimino RIGHT using the K");
    my_putstr(" key (def: right arrow)\n");
    my_putstr("  -t --key-turn={K}    TURN the tetrimino clockwise 90d usin");
    my_putstr("g the K key (def: top arrow)\n");
    my_putstr("  -d --key-drop={K}    DROP the tetrimino using the K key (d");
    my_putstr("ef: down arrow)\n");
    show_help_two();
    return (0);
}
