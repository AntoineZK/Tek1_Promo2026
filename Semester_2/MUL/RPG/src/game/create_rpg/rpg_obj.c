/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** rpg_obj
*/

#include "rpg.h"

static void player_image(void)
{
    rpg->player->image = malloc(sizeof(game_obj *) * 12);
    rpg->player->image[DOWN] = game_obj_create("assets/player/down.png",
    rpg->player->pos, "player_down");
    sfSprite_setTextureRect(rpg->player->image[DOWN]->sprite,
    rpg->player->rect);
    rpg->player->image[UP] = game_obj_create("assets/player/up.png",
    rpg->player->pos, "player_up");
    sfSprite_setTextureRect(rpg->player->image[UP]->sprite,
    rpg->player->rect);
    rpg->player->image[LEFT] = game_obj_create("assets/player/left.png",
    rpg->player->pos, "player_left");
    sfSprite_setTextureRect(rpg->player->image[LEFT]->sprite,
    rpg->player->rect);
    rpg->player->image[RIGHT] = game_obj_create("assets/player/right.png",
    rpg->player->pos, "player_right");
    sfSprite_setTextureRect(rpg->player->image[RIGHT]->sprite,
    rpg->player->rect);
    dash_create();
}

static void player_create(void)
{
    char *tmp = my_open_file("map/mob.txt");
    char **tmp2 = my_str_to_wordarray(tmp, '\n');

    rpg->player = malloc(sizeof(player_t));
    rpg->player = my_memset(rpg->player, 0, sizeof(player_t));
    rpg->player->rect = (sfIntRect) {128, 0, 128, 128};
    rpg->start_pos = find_char(tmp2, 'S');
    rpg->player->pos = find_char(tmp2, 'S');
    rpg->player->clock = sfClock_create();
    rpg->player->life = 100;
    rpg->player->is_anim = malloc(sizeof(int) * 4);
    rpg->player->is_anim = my_memset(rpg->player->is_anim, 0, sizeof(int) * 4);
    player_image();
    monsters(tmp2);
    create_npcs(tmp2);
    free(tmp);
    array_destroy(tmp2);
}

static void info_create(void)
{
    rpg->info = malloc(sizeof(information_t));
    rpg->info->view = sfView_createFromRect((sfFloatRect) {0, 0, 1920, 1080});
    sfView_setCenter(rpg->info->view, (sfVector2f) {960, 540});
}

static void minimap_create(void)
{
    sfFloatRect init_rect = {0, 0, 1920, 1080};

    rpg->mini_map = malloc(sizeof(minimap_t));
    rpg->mini_map = my_memset(rpg->mini_map, 0, sizeof(minimap_t));
    rpg->mini_map->view = sfView_createFromRect(init_rect);
    rpg->mini_map->rect = (sfFloatRect) {0.75f, 0, 0.25f, 0.25f};
    sfView_zoom(rpg->mini_map->view, 1.5f);
}

void rpg_create(rpg_t *rpg)
{
    rpg = my_memset(rpg, 0, sizeof(rpg_t));
    rpg->wait_input = -1;
    rpg->in_game = 0;
    rpg->options = options_create();
    rpg->vid_mode = (sfVideoMode) {1920, 1080, 32};
    rpg->window = sfRenderWindow_create(rpg->vid_mode, "RPG",
    sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->window, 60);
    rpg->view = sfView_createFromRect((sfFloatRect) {0, 0, 1920, 1080});
    sfRenderWindow_setPosition(rpg->window, (sfVector2i) {0, 0});
    sfView_setCenter(rpg->view, (sfVector2f) {960, 540});
    sfView_setViewport(rpg->view, (sfFloatRect) {0, 0, 1, 1});
    sfRenderWindow_setView(rpg->window, rpg->view);
    rpg->map1 = game_obj_create("assets/map/temple.png",
    (sfVector2f) {13440, 0}, "map");
    rpg->map2 = game_obj_create("assets/map/village.png",
    (sfVector2f) {0, 0}, "map");
    scene_load_all(rpg->scenes);
    player_create();
    minimap_create();
    info_create();
    create_particule();
    rpg->joy = joystick_create();
}
