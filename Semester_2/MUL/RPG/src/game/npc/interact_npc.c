/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** interact_npc
*/

#include "rpg.h"

void draw_npc(void)
{
    for (int i = 0; rpg->npcs[i]; ++i) {
        npc_draw(rpg->window, rpg->npcs[i]);
        if (rpg->npcs[i]->is_talking) {
            npc_interact(rpg->window, rpg->npcs[i], 0);
        }
    }
}

void dialogue_display_two(game_obj *obj, sfIntRect rec,
npc_t *npc, sfText *text)
{
    sfText_setString(text, npc->dialogue->message);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 30);
    sfSprite_setPosition(obj->sprite, (sfVector2f){npc->obj->position.x
    - rec.width/2, npc->obj->position.y  - rec.height/2});
    game_obj_set_scale(obj, (sfVector2f) {0.5, 0.5});
    sfText_setPosition(text, (sfVector2f) {npc->obj->position.x -
    rec.width/2 + 20, npc->obj->position.y  - rec.height/2.5});
}

void npc_interaction(void)
{
    for (int i = 0; rpg->npcs[i]; ++i) {
        if (((rpg->event.type == sfEvtKeyPressed &&
        rpg->event.key.code == rpg->options->keys[INTERACT_KEY]) ||
        (rpg->event.type == sfEvtJoystickButtonPressed &&
        sfJoystick_isButtonPressed(0, rpg->joy->interact))) &&
        in_range(rpg->player->pos, rpg->npcs[i]->obj->position, 64)) {
            npc_interact(rpg->window, rpg->npcs[i], 1);
        }
    }
}
