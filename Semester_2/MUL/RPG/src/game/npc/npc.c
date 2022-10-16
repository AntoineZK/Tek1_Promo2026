/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** npc
*/

#include "rpg.h"

npc_t *npc_create(game_obj *obj, dialogue_t *dialogue)
{
    npc_t *npc = malloc(sizeof(npc_t));

    npc->obj = obj;
    npc->is_talking = 0;
    npc->dialogue = dialogue;
    return (npc);
}

void npc_destroy(npc_t *npc)
{
    game_obj_destroy(npc->obj);
    free(npc);
}

void npc_draw(sfRenderWindow *window, npc_t *npc)
{
    sfSprite_setPosition(npc->obj->sprite, npc->obj->position);
    DRAW_SPRITE(window, npc->obj->sprite);
}

void dialogue_display(sfRenderWindow *window, npc_t *npc, int next)
{
    if (npc->dialogue->type == DIALOGUE_END) {
        next ? npc->dialogue = npc->dialogue->next : 0;
        npc->is_talking = 0;
        rpg->player->is_talking = 0;
        rpg->inventory->have_key = 1;
        return;
    }
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/monogram.ttf");
    game_obj *obj = game_obj_create("assets/npc/box.png",
    npc->obj->position, "dialogue");
    sfIntRect rect = sfSprite_getTextureRect(obj->sprite);
    sfText_setFont(text, font);
    dialogue_display_two(obj, rect, npc, text);
    if (npc->dialogue->type == DIALOGUE_MESSAGE) {
        DRAW_SPRITE(window, obj->sprite);
        sfRenderWindow_drawText(window, text, NULL);
    }
    sfFont_destroy(font);
    next ? npc->dialogue = npc->dialogue->next : 0;
}

void npc_interact(sfRenderWindow *window, npc_t *npc, int next)
{
    rpg->player->is_talking = 1;
    if (!npc->is_talking) {
        dialogue_display(window, npc, 0);
        npc->is_talking = 1;
    }
    else
        dialogue_display(window, npc, next);
}
