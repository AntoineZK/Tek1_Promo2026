/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** init_struct
*/

#include "../include/defender.h"

static void init_struct_four(defender_t *def)
{
    def->hg.exit_light = 0;
    def->hg.p_exit_light = 0;
    def->hg.sett_light = 0;
    def->hg.sett_return = 0;
    def->hg.start_light = 0;
    def->hg.p_sett_light = 0;
    def->hg.plus_light = 0;
    def->hg.minus_light = 0;
    def->hg.resume_light = 0;
    def->hg.return_light = 0;
    def->hg.tuto_light = 0;
    def->hg.tuto_return = 0;
    def->cbuffer = sfSoundBuffer_createFromFile("res/click.ogg");
    def->csound = sfSound_create();
    sfSound_setBuffer(def->csound, def->cbuffer);
    def->towbuffer = sfSoundBuffer_createFromFile("res/tower_sound.ogg");
    def->towsound = sfSound_create();
    sfSound_setBuffer(def->towsound, def->towbuffer);
}

static void init_struct_three(defender_t *def)
{
    def->price_tow[FIRE] = 100;
    def->price_tow[STONE] = 200;
    def->price_tow[SLOW] = 150;
    def->price_tow[MOULA] = 300;
    def->price_tow[REDMOON] = 800;
    def->price_tow[OBE] = 500;
    def->price_tow[FIRE2] = 300;
    def->price_tow[STONE2] = 500;
    def->price_tow[SLOW2] = 400;
    def->price_tow[MOULA2] = 600;
    def->price_tow[REDMOON2] = 1500;
    def->price_tow[OBE2] = 1000;
    def->price_tow[FIRE3] = 500;
    def->price_tow[STONE3] = 1000;
    def->price_tow[SLOW3] = 800;
    def->price_tow[MOULA3] = 1200;
    def->price_tow[REDMOON3] = 3000;
    def->price_tow[OBE3] = 2000;
    init_struct_four(def);
}

static void init_struct_two(defender_t *def)
{
    def->clock = sfClock_create();
    def->c_heart = sfClock_create();
    def->c_coin = sfClock_create();
    def->ctower = 1000;
    def->life = 100;
    def->mobs = NULL;
    def->node_val = 0;
    def->ts = NULL;
    def->to_up = 0;
    def->volume = 10;
    def->mob_text = NULL;
    def->wave_list = get_txt_file("data/wave_data.txt");
    def->tower_list = get_txt_file("data/tower_data.txt");
    initialised_checpoint(def);
    highscore_get(def);
    sfMusic_play(def->music);
    init_struct_three(def);
}

void init_struct(defender_t *def, char *map)
{
    def->cmap = map;
    def->map = my_str_to_word_array(map);
    def->vid_mod = (sfVideoMode) {1920, 1080, 32};
    def->wdw = sfRenderWindow_create(def->vid_mod, "Defender",
    sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(def->wdw, 60);
    def->scene = MENU;
    def->music = sfMusic_createFromFile("res/zelda_ost.ogg");
    def->cam = sfView_createFromRect((sfFloatRect) {0, 0, 1920, 1080});
    sfView_setViewport(def->cam, (sfFloatRect) {0, 0, 1, 1});
    sfRenderWindow_setView(def->wdw, def->cam);
    sfMusic_getLoop(def->music);
    def->wave = 0;
    def->mwave = 0;
    def->money = 1000;
    init_struct_two(def);
}
