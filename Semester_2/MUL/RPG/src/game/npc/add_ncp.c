/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** add_ncp
*/

#include "rpg.h"

static void add_ncp(npc_t ***npcs, npc_t *npc)
{
    int len = 0;
    npc_t **new_npcs = NULL;

    for (; (*npcs)[len]; ++len);
    new_npcs = malloc(sizeof(npc_t *) * (len + 2));
    for (int i = 0; i < len; ++i)
        new_npcs[i] = (*npcs)[i];
    new_npcs[len] = npc;
    new_npcs[len + 1] = NULL;
    free(*npcs);
    *npcs = new_npcs;
}

void create_npcs(char **map)
{
    int y = 0;
    npc_t *npc = NULL;
    dialogue_t *dialogue = dialogue_create(DIALOGUE_MESSAGE,
    "Tient, prend cette clé !");

    rpg->npcs = malloc(sizeof(npc_t *));
    rpg->npcs[0] = NULL;
    for (int i = 0; map[i]; ++i) {
        y = i * 128;
        for (int j = 0; map[i][j]; ++j) {
            npc = map[i][j] == '3' ?
            npc_create(game_obj_create("assets/npc/npc.png",
            (sfVector2f) {j * 128, y}, "pnj"), dialogue) : NULL;
            npc ? add_ncp(&rpg->npcs, npc) : 0;
        }
    }
}
