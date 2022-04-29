/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** bsq
*/

#ifndef BSQ_H_
    #define BSQ_H_
    #include "my.h"
    #include "printf.h"
    #include "free.h"

typedef struct bsq_s {
    char **d_map;
    char *c_map;
    char *tmp;
    int nb_line;
    int width;
    int height;
    int max_width;
    int square_size;
    int max_square;
    int max_x;
    int max_y;
    int obstacle;
    int x;
    int y;
} bsq_t;

#endif
bsq_t *final_bsq(bsq_t *bsq);
bsq_t *replace_maps(bsq_t *bsq);
int true_nbline(bsq_t *bsq);
