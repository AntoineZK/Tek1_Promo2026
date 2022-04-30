/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myhunter-antoine.khalidy
** File description:
** scene
*/

#include "../include/my.h"
#include "../include/myhunter.h"

void init_all_scene(hunter_t *hunter)
{
    main_scene(hunter);
    difficulty_scene(hunter);
    game_scene(hunter);
    final_scene(hunter);
}

void main_scene(hunter_t *hunter)
{
    hunter->menu_back = image_creator("assets/botw.jpg", \
    (sfVector2f) {0, 0}, NULL);
    hunter->start = image_creator("assets/play.png", \
    (sfVector2f) {(1900/2) - 100, 300}, NULL);
    hunter->exit = image_creator("assets/exit.png", \
    (sfVector2f) {(1900/2) - 100, 700}, NULL);
}

void difficulty_scene(hunter_t *hunter)
{
    hunter->difficulty_back = image_creator("assets/LVL.png", \
    (sfVector2f) {0, 0}, NULL);
    hunter->easy = image_creator("assets/easy.png", \
    (sfVector2f) {(1900/2) - 80, 200}, NULL);
    hunter->normal = image_creator("assets/normal.png", \
    (sfVector2f) {(1900/2) - 100, 400}, NULL);
    hunter->hard = image_creator("assets/hard.png", \
    (sfVector2f) {(1900/2) - 85, 600}, NULL);
    hunter->home = image_creator("assets/home.png", \
    (sfVector2f) {(1900/2) - 85, 800}, NULL);
}

void game_scene(hunter_t *hunter)
{
    hunter->game_back = image_creator("assets/Forest.png", \
    (sfVector2f) {0, 0}, NULL);
    hunter->link = image_creator("assets/Link.png", \
    (sfVector2f) {1700, 680}, NULL);
    hunter->wyvern = image_creator("assets/Wyvern.png", \
    (sfVector2f) {-100, 250}, NULL);
    hunter->goblin = image_creator("assets/GoblinD.png", \
    (sfVector2f) {-100, 720}, NULL);
}

void final_scene(hunter_t *hunter)
{
    hunter->lose_back = image_creator("assets/ZGameOver.jpg", \
    (sfVector2f) {0, 0}, NULL);
    hunter->win_back = image_creator("assets/hyrulecastle.jpg", \
    (sfVector2f) {0, 0}, NULL);
}
