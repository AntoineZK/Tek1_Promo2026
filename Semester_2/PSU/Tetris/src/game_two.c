/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** game_two
*/

#include "tetris.h"

clock_t input_handler(tetris_t *g, clock_t soft_drop)
{
    if (g->input == g->key_turn) {
        // rotate(g);
    }
    if (g->input == g->key_quit) {
        g->can_continue = false;
    }
    return (soft_drop);
}
