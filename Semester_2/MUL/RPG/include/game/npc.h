/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** npc
*/

#ifndef NPC_H_
    #define NPC_H_

    #include "csfml.h"
    #include "game/game_obj.h"
    #include "game/dialogue.h"

typedef struct npc_s {
    game_obj *obj;
    int is_talking;
    dialogue_t *dialogue;
} npc_t;

npc_t *npc_create(game_obj *obj, dialogue_t *dialogue);
void npc_interact(sfRenderWindow *window, npc_t *npc, int next);
void npc_draw(sfRenderWindow *window, npc_t *npc);
void npc_destroy(npc_t *npc);

#endif
