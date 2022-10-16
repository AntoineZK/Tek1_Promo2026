/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_
    #include "csfml.h"
    #include "hud.h"
    #include "utils.h"
    #include "game/npc.h"
    #include "game/arrow.h"
    #include "game/particule.h"
    #include "game/monster.h"

enum player_status {
    DOWN,
    UP,
    LEFT,
    RIGHT,
    SW_DOWN,
    SW_UP,
    SW_LEFT,
    SW_RIGHT,
    BOW_DOWN,
    BOW_UP,
    BOW_LEFT,
    BOW_RIGHT,
};

enum player_ability {
    DASH,
    SWORD,
    BOW,
    NORMAL,
};

enum controller {
    KEYBOARD,
    JOYSTICK,
};

typedef struct inventory_s {
    game_obj **image;
    int have_sword;
    int have_bow;
    int have_key;
    int have_graal;
} inventory_t;

typedef struct joystick_s {
    int attack;
    int interact;
    int pause;
    int inventory;
    int minimap;
    int dash;
    int mode;
    sfVector2f joy1;
    sfVector2f joy2;
} joystick_t;

typedef struct information_s {
    sfView *view;
} information_t;

typedef struct player_s {
    sfIntRect rect;
    sfVector2f pos;
    sfTime time;
    sfClock *clock;
    float sec;
    game_obj **image;
    int status;
    int *is_anim;
    int is_talking;
    int life;
    sfVector2f last_pose;
    int *is_dash;
    int is_dash_status;
    sfClock **cd_clock;
    sfTime *cd_time;
    float *cd_sec;
    int *is_able;
    float *cd_value;
    int attack_mode;
    arrow_t *arrow;
    int *sword;
    int sword_status;
    sfVector2f arrow_last_pos;
} player_t;

typedef struct minimap_s {
    sfView *view;
    sfFloatRect rect;
} minimap_t;

typedef struct rpg_s {
    sfRenderWindow *window;
    sfView *view;
    sfVideoMode vid_mode;
    sfEvent event;
    scene *scenes[6];
    char **c_map;
    char ***d_map;
    game_obj *map1;
    game_obj *map2;
    int in_game;
    inventory_t *inventory;
    sfVector2f start_pos;
    player_t *player;
    minimap_t *mini_map;
    information_t *info;
    int save_value;
    int wait_input;
    options_t *options;
    label *wait_label;
    int controller;
    npc_t **npcs;
    monster_t **monsters;
    joystick_t *joy;
    int scene;
    particule_t **particules;
} rpg_t;

extern rpg_t *rpg;

void rpg_destroy(rpg_t *rpg);
void bow_create(void);
void rpg_create(rpg_t *rpg);
int rpg_events_loop(void);
void draw_minimap(void);
void draw_game(void);
sfVector2f find_char(char **map, char character);
int set_save(char *save_file);
void get_save(char *save);
sfVector2i double_to_int(double x, double y, int to_divide, char **map);
int find_char_map(char **map, sfVector2f value, char to_find, int hitbox);
game_obj *monster_create(char *file, sfVector2f pos, sfIntRect rect);
void player_draw(void);
void d_text_pol(sfRenderWindow *wdw, char *line, sfVector2f pos, int pol);
void d_text_col(sfRenderWindow *wdw, char *line, sfVector2f pos, sfColor col);
void monster_draw(monster_t *mstr);
void draw_info(void);
void animation_player(game_obj *game_obj, int length);
sfVector2f calcul_vector(sfVector2f a, sfVector2f b);
monster_t *type_boss(monster_t *mstr, sfVector2f pos);
void check_controller(void);
void bow(int movement);
monster_t *type_skeleton(monster_t *mstr, sfVector2f pos);
void set_pos_player(void);
joystick_t *joystick_create(void);
int choose_mode(void);
void player_event(void);
void npc_interaction(void);
monster_t *create_monster(sfVector2f pos, int type_monster);
void move_joystick(void);
void move_keyboard(void);
void dash_keyboard(void);
void dash_joystick(void);
void set_pos_monster(monster_t *mstr);
int keys_used(sfKeyCode key);
void collision(void);
void dialogue_display_two(game_obj *obj, sfIntRect rec,
npc_t *npc, sfText *text);
void create_particule(void);
void dash(int movement);
void draw_mobs(void);
void dash_create(void);
sfVector2f calcul_arrow(sfVector2f pos_player, sfVector2f pos_mouse);
sfVector2i double_to_int(double x, double y, int to_divide, char **map);
void joystick_sword(void);
void draw_npc(void);
int activate_inventory(void);
void monster_animation(monster_t *mstr, int movement);
int is_outside_map(sfVector2f pos);
void keyboard_bow(void);
arrow_t *arrow_create(sfVector2f position, sfVector2f direction);
void check_used(void);
sfVector2f walls(sfVector2f pos, int *anim, int value, int hitbox);
int check_arrow_collision(sfVector2f pos, float rotation);
void monster_event(monster_t *mstr);
void dash_animation(game_obj *image, int length);
void keyboard_sword(void);
void monsters(char **map);
void animation(sfSprite *sprite, sfIntRect anim, int max_decal);
int nb_line(char **map);
void sword(int movement);
void draw_inventory(void);
void cooldown(void);
void gameplay_destroy(void);
void sword_animation(game_obj *game_obj, int length);
int in_range(sfVector2f pos_a, sfVector2f pos_b, float range);
void follow_player(sfVector2f pos_a, sfVector2f pos_b, monster_t *mstr);
void game_handler(void);
void set_angle_monster(monster_t *mstr);
void joystick_bow(void);
void move_monster(monster_t *mstr, int movement);
void create_inventory(void);
void player_attack_touch(player_t *player);
void create_npcs(char **map);

#endif
