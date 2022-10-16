/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** init_struct
*/

#include "tetris.h"

void init_struct(tetris_t *g)
{
    g->level = 1;
    g->key_left = KEY_LEFT;
    g->key_right = KEY_RIGHT;
    g->key_drop = KEY_DOWN;
    g->key_turn = KEY_UP;
    g->key_quit = 'q';
    g->key_pause = ' ';
    g->col = 10;
    g->line = 20;
    g->hide = false;
    g->debug = false;
    g->can_continue = true;
    g->piece = NULL;
}

void my_shownbr(int nb)
{
    int tmp = nb;
    int size = 1;
    for (; tmp >= 10; size++)
        tmp /= 10;
    char *cnb = malloc(sizeof(char) * (size + 1));
    if (nb < 0)
        nb *= (-1);
    for (int i = 0; i < size; i++) {
        tmp = nb;
        for (int j = 1; j < (size - i); j++)
            tmp /= 10;
        cnb[i] = ('0' + (tmp % 10));
    }
    write(1, cnb, my_strlen(cnb));
}

void show_key(int key)
{
    if (key == 260)
        write(1, "KEY_LEFT", 8);
    if (key == 261)
        write(1, "KEY_RIGHT", 9);
    if (key == 259)
        write(1, "KEY_UP", 6);
    if (key == 258)
        my_putstr("KEY_DOWN");
    if (key < 258)
        write(1, &key, 1);
    my_putstr(" (");
    my_shownbr(key);
    my_putstr(")\n");
}

int show_debug_2(tetris_t *g)
{
    my_putstr("\nSize: ");
    my_shownbr(g->line);
    my_putstr("*");
    my_shownbr(g->col);
    my_putstr("\n\nNumber of tetriminos: ");
    my_shownbr(list_len(g->piece));
    my_putstr("\n");
    show_list(g->piece);
    return (0);
}

int show_debug(tetris_t *g)
{
    my_putstr("Key left: ");
    show_key(g->key_left);
    my_putstr("Key right: ");
    show_key(g->key_right);
    my_putstr("Key turn: ");
    show_key(g->key_turn);
    my_putstr("Key drop: ");
    show_key(g->key_drop);
    my_putstr("Key quit: ");
    show_key(g->key_quit);
    my_putstr("Key pause: ");
    show_key(g->key_pause);
    my_putstr("Next: ");
    if (g->hide == TRUE)
        my_putstr("No\n");
    else
        my_putstr("Yes\n");
    my_putstr("Level: ");
    my_shownbr(g->level);
    return (show_debug_2(g));
}
