/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** maths
*/

#include "utils/maths.h"

double vector_norm(sfVector2f vec)
{
    return (sqrt(vec.x * vec.x + vec.y * vec.y));
}

float vector_multiply(sfVector2f vec1, sfVector2f vec2)
{
    return (vec1.x * vec2.x + vec1.y * vec2.y);
}

double vector_angle(sfVector2f vec1, sfVector2f vec2)
{
    return (acos(vector_multiply(vec1, vec2) / (vector_norm(vec1) *
    vector_norm(vec2))));
}
