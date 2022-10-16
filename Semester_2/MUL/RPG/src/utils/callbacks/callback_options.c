/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** callback_options
*/

#include "utils/callback.h"

unsigned int const resolutions[3][2] = {{800, 600}, {1536, 816}, {1920, 1080}};

int set_key(char **args)
{
    rpg->wait_label = label_get_from_name(args[0]);
    label_set_text(rpg->wait_label, "...");
    rpg->wait_input = my_getnbr(args[1]);
    return (0);
}

int decrease_volume(char **args)
{
    if (args[0][0] == '0')
        rpg->options->sound_volume -= 10;
    else
        rpg->options->music_volume -= 10;
    return (0);
}

int increase_volume(char **args)
{
    if (args[0][0] == '0')
        rpg->options->sound_volume += 10;
    else
        rpg->options->music_volume += 10;
    return (0);
}

int decrease_resolution(char **args)
{
    rpg->options->resolution_index > 0 ? rpg->options->resolution_index-- : 0;
    label *label = label_get_from_name("resolution");
    char *text = malloc(sizeof(char));
    text[0] = '\0';
    my_strcat_dyn(&text,
    my_itoa(resolutions[rpg->options->resolution_index][0]));
    my_strcat_dyn(&text, "x");
    my_strcat_dyn(&text,
    my_itoa(resolutions[rpg->options->resolution_index][1]));
    rpg->options->resolution[0] =
    resolutions[rpg->options->resolution_index][0];
    rpg->options->resolution[1] =
    resolutions[rpg->options->resolution_index][1];
    label_set_text(label, text);
    return (0);
}

int increase_resolution(char **args)
{
    rpg->options->resolution_index < 2 ? rpg->options->resolution_index++ : 0;
    label *label = label_get_from_name("resolution");
    char *text = malloc(sizeof(char));
    text[0] = '\0';
    my_strcat_dyn(&text,
    my_itoa(resolutions[rpg->options->resolution_index][0]));
    my_strcat_dyn(&text, "x");
    my_strcat_dyn(&text,
    my_itoa(resolutions[rpg->options->resolution_index][1]));
    rpg->options->resolution[0] =
    resolutions[rpg->options->resolution_index][0];
    rpg->options->resolution[1] =
    resolutions[rpg->options->resolution_index][1];
    label_set_text(label, text);
    return (0);
}
