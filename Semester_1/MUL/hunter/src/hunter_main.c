/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myhunter-antoine.khalidy
** File description:
** hunter_main
*/

#include "../include/my.h"
#include "../include/myhunter.h"

hunter_t *init_struct(hunter_t *hunter)
{
    hunter->clock_monster = sfClock_create();
    hunter->sec_monster = 0;
    hunter->video_mode = sfVideoMode_getDesktopMode();
    hunter->window = sfRenderWindow_create(hunter->video_mode, "Myhunter",
    sfResize | sfClose | sfFullscreen, NULL);
    hunter->scene = 0;
    sfRenderWindow_setFramerateLimit(hunter->window, 60);
    hunter->score = 0;
    hunter->highscore = 0;
    highscore_get(hunter);
    highscore_get(hunter);
    hunter->nb_life = 4;
    hunter->zelda_ost = sfMusic_createFromFile("assets/zelda_ost.ogg");
    sfMusic_getLoop(hunter->zelda_ost);
    hunter->zelda_bow_buffer = sfSoundBuffer_createFromFile(\
    "assets/zelda_bow.ogg");
    hunter->zelda_bow = sfSound_create();
    sfSound_setBuffer(hunter->zelda_bow, hunter->zelda_bow_buffer);
    return (hunter);

}

void hunter(void)
{
    hunter_t *hunter = malloc(sizeof(hunter_t));
    hunter = init_struct(hunter);
    init_all_scene(hunter);
    sfMusic_play(hunter->zelda_ost);
    while (sfRenderWindow_isOpen(hunter->window)) {
        while (sfRenderWindow_pollEvent(hunter->window, &hunter->event))
            hunter = hunter_event(hunter);
        scene_management(hunter);
        hunter = revive_mobs(hunter);
        if (hunter->score >= 50)
            hunter->scene = 6;
        sfRenderWindow_display(hunter->window);
    }
    hunter->score > hunter->highscore ? hunter->highscore = hunter->score : 0;
    highscore_set(hunter);
    destroy_one(hunter);
    destroy_two(hunter);
    free(hunter);
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        description();
        return (0);
    }
    hunter();
    return (0);
}
