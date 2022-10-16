/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** game_main
*/

#include "rpg.h"

rpg_t *rpg;

static void display_scenes(void)
{
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
        rpg_events_loop();
    sfRenderWindow_setView(rpg->window,rpg->view);
    for (int i = 0; rpg->scenes[i]; ++i) {
        if (rpg->scenes[i]->selected) {
            scene_draw(rpg->window, rpg->scenes[i]);
        }
    }
    rpg->in_game ? game_handler() : 0;
}

static void basic_keys_names_2(rpg_t *rpg, label *variable)
{
    variable = label_get_from_name("arrow");
    label_set_text(variable, get_keyname(rpg->options->keys[ARROW_KEY]));
    variable = label_get_from_name("dash");
    label_set_text(variable, get_keyname(rpg->options->keys[DASH_KEY]));
    variable = label_get_from_name("interact");
    label_set_text(variable, get_keyname(rpg->options->keys[INTERACT_KEY]));
    variable = label_get_from_name("pause");
    label_set_text(variable, get_keyname(rpg->options->keys[PAUSE_KEY]));
    variable = label_get_from_name("inventory");
    label_set_text(variable, get_keyname(rpg->options->keys[INVENTORY_KEY]));
    variable = label_get_from_name("map");
    label_set_text(variable, get_keyname(rpg->options->keys[MINIMAP_KEY]));
}

void basic_keys_names(rpg_t *rpg)
{
    label *variable = label_get_from_name("up");
    label_set_text(variable, get_keyname(rpg->options->keys[UP_KEY]));
    variable = label_get_from_name("down");
    label_set_text(variable, get_keyname(rpg->options->keys[DOWN_KEY]));
    variable = label_get_from_name("left");
    label_set_text(variable, get_keyname(rpg->options->keys[LEFT_KEY]));
    variable = label_get_from_name("right");
    label_set_text(variable, get_keyname(rpg->options->keys[RIGHT_KEY]));
    variable = label_get_from_name("hit");
    label_set_text(variable, "LClick");
    basic_keys_names_2(rpg, variable);
}

int main(void)
{
    sfClock *seed_clock = sfClock_create();

    rpg = malloc(sizeof(rpg_t));
    rpg_create(rpg);
    basic_keys_names(rpg);
    if (!rpg)
        return (84);
    srand(sfClock_getElapsedTime(seed_clock).microseconds);
    sfClock_destroy(seed_clock);
    rand();
    check_controller();
    while (sfRenderWindow_isOpen(rpg->window)) {
        display_scenes();
        sfRenderWindow_display(rpg->window);
    }
    rpg->save_value == 1 ? set_save("save/save1.txt") : 0;
    rpg->save_value == 2 ? set_save("save/save2.txt") : 0;
    rpg->save_value == 3 ? set_save("save/save3.txt") : 0;
    rpg_destroy(rpg);
    return (0);
}
