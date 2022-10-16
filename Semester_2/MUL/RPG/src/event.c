/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** event
*/

#include "rpg.h"

static int buttons_events(sfVector2f m_pos, scene *scene)
{
    int code = 0;

    for (int j = 0; scene->buttons[j]; j++) {
        code = button_is_clicked(scene->buttons[j], m_pos.x, m_pos.y);
        if (code == 2)
            sfRenderWindow_close(rpg->window);
        if (code != 1)
            return (0);
    }
    return (1);
}

static int events_loop(sfVector2f m_pos, scene *scene)
{
    if (rpg->event.type == sfEvtMouseButtonReleased && scene->selected) {
        if (!buttons_events(m_pos, scene))
            return (0);
    }
    if (rpg->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    return (1);
}

int keys_used(sfKeyCode key)
{
    for (int i = 0; rpg->options->keys[i] != -1; ++i) {
        if (key == rpg->options->keys[i])
            return (1);
    }
    return (0);
}

static void rpg_key_pressed(void)
{
    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->wait_input != -1)
            check_used();
        rpg->event.key.code == sfKeyEscape ?
        sfRenderWindow_close(rpg->window) : 0;
    }
    npc_interaction();
    if (choose_mode())
        return;
    if (activate_inventory())
        return;
}

int rpg_events_loop(void)
{
    int len = 1;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->window);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(rpg->window,
    mouse, rpg->view);

    for (; rpg->scenes[len]; len++);
    for (int i = len - 1; i >= 0; --i) {
        if (rpg->scenes[i]->selected &&
        !events_loop(mouse_pos, rpg->scenes[i]))
            break;
        else if (rpg->scenes[i]->selected)
            break;
    }
    if (rpg->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    rpg_key_pressed();
    return (0);
}
