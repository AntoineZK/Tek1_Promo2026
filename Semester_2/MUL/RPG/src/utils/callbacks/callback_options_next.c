/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** callback_options_next
*/

#include "utils/callback.h"

static void center_window(void)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    sfRenderWindow_setPosition(rpg->window, (sfVector2i)
    {mode.width / 2 - rpg->options->resolution[0] / 2,
    mode.height / 2 - rpg->options->resolution[1] / 2});
}

int validate_resolution(char **args)
{
    sfRenderWindow_setSize(rpg->window, (sfVector2u)
    {rpg->options->resolution[0], rpg->options->resolution[1]});
    center_window();
    return (0);
}
