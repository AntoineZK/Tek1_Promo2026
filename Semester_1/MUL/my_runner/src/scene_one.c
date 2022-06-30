/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** runner_menu
*/

#include "../include/my.h"
#include "../include/myrunner.h"

void init_all_scene(runner_t *runner)
{
    main_scene(runner);
    character_scene(runner);
    game_scene_ichigo(runner);
    game_scene_toshiro(runner);
    win_scene(runner);
    lose_scene(runner);
}

void main_scene(runner_t *runner)
{
    runner->menu_bg = image_creator("assets/back_menu.png", \
    (sfVector2f) {0, 0}, NULL, IMAGE);
    runner->menu_start = image_creator("assets/start_b.png", \
    (sfVector2f) {240, 200}, NULL, IMAGE);
    runner->menu_exit = image_creator("assets/exit_b.png", \
    (sfVector2f) {250, 600}, NULL, IMAGE);
}

void character_scene(runner_t *runner)
{
    runner->character_bg = image_creator("assets/ichigo_toshi.jpg", \
    (sfVector2f) {0, 0}, NULL, IMAGE);
    runner->character_ichigo = image_creator("assets/ichigo_b.png", \
    (sfVector2f) {100, 150}, NULL, IMAGE);
    runner->character_toshiro = image_creator("assets/toshiro_b.png", \
    (sfVector2f) {100, 400}, NULL, IMAGE);
    runner->character_home = image_creator("assets/home_char.png", \
    (sfVector2f) {100, 650}, NULL, IMAGE);
}

void game_scene_ichigo(runner_t *runner)
{
    runner->game_background1 = image_creator("assets/sky.png", \
    (sfVector2f) {0, 0}, NULL, IMAGE);
    runner->parralax_one = image_creator("assets/bg1.png", \
    (sfVector2f) {0, 0}, NULL, IMAGE);
    sfSprite_setPosition(runner->parralax_one->sprite_copy, (sfVector2f) \
    {runner->parralax_one->position.x + sfTexture_getSize(\
    runner->parralax_one->texture).x, 0});
    runner->parralax_two = image_creator("assets/bg3.png", \
    (sfVector2f) {0, 0}, NULL, IMAGE);
    sfSprite_setPosition(runner->parralax_two->sprite_copy, (sfVector2f) \
    {runner->parralax_two->position.x + sfTexture_getSize(\
    runner->parralax_two->texture).x, 0});
    runner->ichigo_run = image_creator("assets/ichigo_run.png", \
    (sfVector2f) {50, 600}, NULL, CHARACTER);
    runner->ichigo_jump = image_creator("assets/ichigo jump.png", \
    (sfVector2f) {50, 600}, NULL, CHARACTER);
    sfSprite_setTextureRect(runner->ichigo_jump->sprite, \
    (sfIntRect) {0, 0, 115, 115});
}

void game_scene_toshiro(runner_t *runner)
{
    runner->game_background2 = image_creator("assets/sky.png", \
    (sfVector2f) {0, 0}, NULL, IMAGE);
    runner->toshiro_run = image_creator("assets/toshiro_run.png", \
    (sfVector2f) {50, 600}, NULL, CHARACTER);
    runner->toshiro_jump = image_creator("assets/toshiro_jump.png", \
    (sfVector2f) {50, 600}, NULL, CHARACTER);
    sfSprite_setTextureRect(runner->toshiro_jump->sprite, \
    (sfIntRect) {0, 0, 100, 150});
}
