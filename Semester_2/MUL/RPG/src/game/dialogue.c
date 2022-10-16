/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** dialogue
*/

#include "game/dialogue.h"

dialogue_t *dialogue_create(dialogue_type_t type, char const *message)
{
    dialogue_t *dialogue = malloc(sizeof(dialogue_t));

    if (!dialogue)
        return (NULL);
    dialogue->type = type;
    dialogue->message = my_strcpy(message);
    dialogue->choices = NULL;
    dialogue->callback = NULL;
    dialogue->next = malloc(sizeof(dialogue_t));
    dialogue->next->type = DIALOGUE_END;
    dialogue->next->next = dialogue;
    return (dialogue);
}

void diaogue_append(dialogue_t *root, dialogue_t *node)
{
    return;
}
