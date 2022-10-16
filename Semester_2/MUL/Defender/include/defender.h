/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** defender
*/

#ifndef DEFENDER_H_
    #define DEFENDER_H_
    #include "scene.h"
    #include "my.h"
    #include "game.h"

typedef struct text_s {
    sfText *txt;
    sfFont *font;
    sfColor color;
} text_t;

typedef struct checkpoint_s {
    char direc;
    int limit;
} checkpoint_t;

typedef struct defender_s {
    sfEvent event;
    sfRenderWindow *wdw;
    sfVideoMode vid_mod;
    sfMusic *music;
    sfClock *clock;
    sfTime time;
    sfView *cam;
    int scene;
    char **map;
    char *cmap;
    sfClock *c_heart;
    sfTime t_heart;
    float sec_heart;
    sfClock *c_coin;
    sfTime t_coin;
    float sec_coin;
    char **wave_list;
    char **tower_list;
    sfTexture *mob_text;
    int node_val;
    int mwave;
    int wave;
    int ctower;
    float volume;
    int to_up;
    int x_int;
    int y_int;
    int life;
    int money;
    int price_tow[18];
    int end;
    sfSound *csound;
    sfSoundBuffer *cbuffer;
    sfSound *towsound;
    sfSoundBuffer *towbuffer;
    mob_t *mobs;
    tower_t *ts;
    checkpoint_t cp[7];
    menu_t menu;
    game_t game;
    settings_t sett;
    tuto_t tuto;
    pause_t pause;
    hg_t hg;
} defender_t;

#endif

// MAP
map_t *print_map(defender_t *def, map_t *map);
char *get_map(char *filepath);
map_t *load_map(char const *map);

// DESCRIPTION
int description_0(void);
int description_84(void);

// TOWER & MOBS
char **get_txt_file(char *filepath);
void mob_loop(defender_t *g);
void initialised_checpoint(defender_t *g);
void tower_loop(defender_t *g);
sfVector2f center_tower(double x, double y);
void place_tower(defender_t *def, double x, double y);
void tower_upgrade(defender_t *def, double x, double y);
void tower_add(defender_t *g, char **wave_data, sfVector2f pos, sfIntRect *re);
void tower_update(defender_t *g, char **wave_data, sfIntRect *rect);
sfVector2f have_tower(double x, double y);
mob_t *wave_creator(defender_t *g, sfVector2f pos);
int is_range(sfVector2f tower, sfVector2f mob, float range);
void time_action(defender_t *g);
void draw_shoot(defender_t *g, sfColor color);
void upgrade_text(defender_t *def, char *up_price);
void display_life(defender_t *def, char *line, sfVector2f pos, sfVector2f siz);

// EVENT
void defender_event(defender_t *def);

// INIT & SCENE
void init_all(defender_t *def);
void scene_handler(defender_t *def, map_t *game);
void init_struct(defender_t *def, char *map);
void init_tuto_pause_two(defender_t *def);
void init_game_two(defender_t *def);

// DRAW
void draw_menu(defender_t *def);
void draw_game(defender_t *def, map_t *game);
void text_game(defender_t *def, map_t *game);
void draw_tuto(defender_t *def);
void draw_pause(defender_t *def);
void draw_settings(defender_t *def);
void price_tower_one(defender_t *def);

// UTILS
char **my_stwa(char *str, char limit, char end);
image_t *image_create(const char *file, sfVector2f pos);
int click_btton(image_t *image, int x, int y);
void display_text(defender_t *def, char *line, sfVector2f pos, int pol);
int highscore_get(defender_t *def);
int highscore_set(defender_t *def);
void draw_sprite(defender_t *def, image_t *image);
void d_price(defender_t *def, char *line, sfVector2f pos, sfColor color);
void sfDestroy(image_t *image);

// VALGRIND
void destroy_all(defender_t *def);
void free_element_map(map_t *list_map);
void free_tower(tower_t *ts);
void free_mobs(mob_t *ts);
void free_all(defender_t *def);

// MATH
sfVector2f find_char(defender_t *def, char character);
char find_char_map(defender_t *def, double x, double y);
void double_to_int(defender_t *def, double x, double y);

// HIGHLIGHT
void highlight_draw_menu(defender_t *def);
void highlight_evt(defender_t *def, sfVector2f mou);

// ANIMATION
void animation_heart(defender_t *def);
void animation_coin(defender_t *def);
void anim_obe(sfSprite *sprite);
void anim_redm(sfSprite *sprite);
void anim_tower_one(defender_t *def, sfVector2f pos);
void anim_tower_two(defender_t *def, sfVector2f pos);
void animation_goblin(defender_t *def);
