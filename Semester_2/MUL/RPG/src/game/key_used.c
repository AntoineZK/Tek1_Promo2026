/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** key_used
*/

#include "rpg.h"

void check_used(void)
{
    if (!(keys_used(rpg->event.key.code))) {
        rpg->options->keys[rpg->wait_input] = rpg->event.key.code;
        label_set_text(rpg->wait_label, get_keyname
        (rpg->event.key.code));
        rpg->wait_label = NULL;
        rpg->wait_input = -1;
    } else {
        label_set_text(rpg->wait_label, "Used");
        rpg->wait_label = NULL;
        rpg->wait_input = -1;
    }
}
