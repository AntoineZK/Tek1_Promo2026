/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** upgrade
*/

#include "../include/defender.h"

void upgrade_text(defender_t *def, char *up_price)
{
    tower_t *backup = def->ts;
    for (int i = 0; i < def->node_val; i++, def->ts = def->ts->next);
    if (def->ts != NULL && def->ts->tow_id + 6 <= 15) {
        up_price = int_to_char(def->price_tow[def->ts->tow_id + 6]);
    } else
        up_price = my_strcat(up_price, "Not able to\nlevel up");
    draw_sprite(def, def->game.g_upgrade);
    if (def->to_up == 0 ||
    def->money < def->price_tow[def->ts->tow_id + 6]) {
        d_price(def, "Level Up = ", (sfVector2f) {1475, 460}, sfRed);
        d_price(def, up_price, (sfVector2f) {1650, 460}, sfRed);
    } else if (def->to_up == 1 && def->money >=
    def->price_tow[def->ts->tow_id + 6]) {
        d_price(def, "Level Up = ", (sfVector2f) {1475, 460}, sfWhite);
        d_price(def, up_price, (sfVector2f) {1650, 460}, sfWhite);
    }
    free(up_price);
    def->ts = backup;
}
