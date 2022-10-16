/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** rpg_obj3
*/

#include "rpg.h"

static void add_monster(monster_t ***monsters, monster_t *monster)
{
    int len = 0;
    monster_t **new_monsters = NULL;

    for (; (*monsters)[len]; ++len);
    new_monsters = malloc(sizeof(monster_t *) * (len + 2));
    for (int i = 0; i < len; ++i)
        new_monsters[i] = (*monsters)[i];
    new_monsters[len] = monster;
    new_monsters[len + 1] = NULL;
    free(*monsters);
    *monsters = new_monsters;
}

static int monster_choice(char const c)
{
    if (c == '4')
        return (SKELETON);
    if (c == '2')
        return (BOSS);
    return (-1);
}

void monsters(char **map)
{
    int y = 0;
    monster_t *monster = NULL;
    int choice = 0;

    rpg->monsters = malloc(sizeof(monster_t *));
    rpg->monsters[0] = NULL;
    for (int i = 0; map[i]; ++i) {
        y = i * 128;
        for (int j = 0; map[i][j]; ++j) {
            choice = monster_choice(map[i][j]);
            monster = choice != -1 ?
            create_monster((sfVector2f) {j * 128, y}, choice) : NULL;
            monster ? add_monster(&rpg->monsters, monster) : 0;
        }
    }
    create_inventory();
}

void create_inventory(void)
{
    rpg->inventory = malloc(sizeof(inventory_t));
    rpg->inventory = my_memset(rpg->inventory, 0, sizeof(inventory_t));
    rpg->inventory->image = malloc(sizeof(game_obj *) * 7);
    rpg->inventory->image[0] = game_obj_create(
        "assets/inventory/inventory.png", (sfVector2f) {500, 0}, "inventory");
    rpg->inventory->image[1] = game_obj_create(
        "assets/inventory/sword_logo.png", (sfVector2f) {1200, 185}, "sword");
    rpg->inventory->image[2] = game_obj_create("assets/inventory/bow_logo.png",
    (sfVector2f) {1200, 385}, "bow");
    rpg->inventory->image[3] = game_obj_create("assets/inventory/key_logo.png",
    (sfVector2f) {1200, 630}, "key");
    rpg->inventory->image[4] = game_obj_create(
        "assets/inventory/graal_logo.png", (sfVector2f) {1205, 805}, "graal");
    rpg->inventory->image[5] = game_obj_create("assets/inventory/frame.png",
    (sfVector2f) {735, 200}, "frame");
    rpg->inventory->image[6] = game_obj_create(
        "assets/inventory/character.png", (sfVector2f) {800, 265}, "charac");
}

void bow_create(void)
{
    rpg->player->image[BOW_DOWN] = game_obj_create
    ("assets/player/sword_down.png", rpg->player->pos, "bow_down");
    rpg->player->image[BOW_UP] = game_obj_create
    ("assets/player/bow_up.png", rpg->player->pos, "bow_up");
    rpg->player->image[BOW_LEFT] = game_obj_create
    ("assets/player/bow_left.png", rpg->player->pos, "bow_left");
    rpg->player->image[BOW_RIGHT] = game_obj_create
    ("assets/player/bow_right.png", rpg->player->pos, "bow_right");
}
