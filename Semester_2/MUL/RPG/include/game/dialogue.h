/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** dialogue
*/

#ifndef DIALOGUE_H_
    #define DIALOGUE_H_
    #include "csfml.h"
    #include <stdlib.h>
    #include "game/game_obj.h"

typedef enum dialgoue_type_e {
    DIALOGUE_MESSAGE,
    DIALOGUE_CHOICE,
    DIALOGUE_CALLBACK,
    DIALOGUE_END,
} dialogue_type_t;

typedef struct dialogue_s {
    dialogue_type_t type;
    char *message;
    char **choices;
    int (*callback)(void *);
    struct dialogue_s *next;
} dialogue_t;

dialogue_t *dialogue_create(dialogue_type_t type, char const *message);
#endif
