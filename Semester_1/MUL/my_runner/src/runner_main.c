/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/myrunner.h"

runner_t *init_struct(runner_t *runner)
{
    runner->nb_sprite = 0;
    runner->sec_ichigo = 0;
    runner->sec_toshiro = 0;
    runner->video_mode = sfVideoMode_getDesktopMode();
    runner->window = sfRenderWindow_create(runner->video_mode, "MyRunner",
    sfResize | sfClose | sfFullscreen, NULL);
    runner->scene = 0;
    sfRenderWindow_setFramerateLimit(runner->window, 60);
    runner->jump = 0;
    runner->clock_ichigo = sfClock_create();
    runner->clock_toshiro = sfClock_create();
    runner->score = 0;
    runner->highscore = 0;
    runner->anti_jump = 0;
    highscore_get(runner);
    runner->map_value = 0;
    return (runner);
}

runner_t *init_struct_two(runner_t *runner)
{
    runner->ost = sfMusic_createFromFile("assets/bleach_ost.ogg");
    sfMusic_setVolume(runner->ost, 20);
    sfMusic_getLoop(runner->ost);
    runner->sound_jump_buffer =
    sfSoundBuffer_createFromFile("assets/bleach_jump.ogg");
    runner->sound_jump = sfSound_create();
    sfSound_setBuffer(runner->sound_jump, runner->sound_jump_buffer);
    return (runner);
}

int runner(linked_list *game)
{
    runner_t *runner = malloc(sizeof(runner_t));
    runner = init_struct(runner);
    runner = init_struct_two(runner);
    sfMusic_play(runner->ost);
    init_all_scene(runner);
    while (sfRenderWindow_isOpen(runner->window)) {
        while (sfRenderWindow_pollEvent(runner->window, &runner->event))
            runner = runner_event(runner);
        scene_management(runner, game);
        sfRenderWindow_display(runner->window);
    }
    if (runner->score > runner->highscore)
        runner->highscore = runner->score;
    destroy_one(runner);
    destroy_two(runner);
    highscore_set(runner);
    free (runner);
    return (0);
}

int main(int argc, char **argv)
{
    char *map;
    if (argc < 2) {
        my_putstr("Invalid Argument");
        return (84);
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        description();
        return (0);
    }
    map = open_map(argv[1]);
    if (map == NULL) {
        my_putstr("Invalid Map");
        return (84);
    } else {
        linked_list *game_objects = load_map(map, 0, 0);
        free(map);
        runner(game_objects);
        free(game_objects);
    }
    return (0);
}
