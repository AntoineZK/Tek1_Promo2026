/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** collision_manager
*/

#include "../include/my.h"
#include "../include/myrunner.h"

spritesheet_t *slide_gravity_manager(spritesheet_t *player, int y)
{
    if (player->slide) {
        player->position.y += y;
        player->slide_time++;
    }
    return (player);
}

int collision_manager(spritesheet_t *player, linked_list *map,
runner_t *runner)
{
    player->slide = 1;
    while (map) {
        if (right_collision(player, map->value, runner->x_movement))
            if (map_value(map) == 1 || map_value(map) == 2)
                return (map_value(map));
        if (top_collision(player, map->value, runner->y_movement)) {
            player->position.y += 0.01;
            if (map_value(map) == 1 || map_value(map) == 2)
                return (map_value(map));
        }
        if (bottom_collision(player, map->value, runner->y_movement)) {
            if (map_value(map) == 1 || map_value(map) == 2)
                return (map_value(map));
            player->slide = 0;
            runner->anti_jump = 0;
        }
        map = map->next;
    }
    player = slide_gravity_manager(player, runner->y_movement);
    return (0);
}

runner_t *death_management_ichigo(runner_t *runner, linked_list *game)
{
    runner->x_movement = 9;
    runner->y_movement = 7.5;
    int result_run = 0;
    result_run = collision_manager(runner->ichigo_run, game, runner);
    if (result_run == 1)
        runner->scene = 5;
    else if (result_run == 2)
        runner->scene = 4;
    int result_jump = 0;
    result_jump = collision_manager(runner->ichigo_jump, game, runner);
    if (result_jump == 1)
        runner->scene = 5;
    else if (result_jump == 2)
        runner->scene = 4;
    if (runner->ichigo_run->position.y >= runner->video_mode.height)
        runner->scene = 5;
    if (runner->ichigo_run->position.x <= -115)
        runner->scene = 5;
    return (runner);
}

runner_t *death_management_toshiro(runner_t *runner, linked_list *game)
{
    runner->x_movement = 9;
    runner->y_movement = 7.5;
    int result_run;
    result_run = collision_manager(runner->toshiro_run, game, runner);
    if (result_run == 1)
        runner->scene = 5;
    else if (result_run == 2)
        runner->scene = 4;
    int result_jump;
    result_jump = collision_manager(runner->toshiro_jump, game, runner);
    if (result_jump == 1)
        runner->scene = 5;
    else if (result_jump == 2)
        runner->scene = 4;
    if (runner->toshiro_run->position.y >= runner->video_mode.height)
        runner->scene = 5;
    if (runner->toshiro_run->position.x <= -115)
        runner->scene = 5;
    return (runner);
}
