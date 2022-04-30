/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** myrunner
*/

#ifndef MYRUNNER_H_
    #define MYRUNNER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <time.h>
    #include <SFML/Window.h>
#endif

typedef enum imageType_s {
    PIKES,
    DECK,
    CHARACTER,
    IMAGE,
    WIN,
} imageType_t;

typedef struct spritesheet_s {
    sfSprite *sprite;
    sfSprite *sprite_copy;
    sfTexture *texture;
    sfVector2f position;
    imageType_t type;
    sfIntRect rect;
    int jumped;
    int slide_time;
    int slide;
} spritesheet_t;

typedef struct linked_list {
    spritesheet_t *value;
    struct linked_list *next;
} linked_list;

typedef struct text_s {
    sfText *txt;
    sfFont *font;
    sfColor color;
} text_t;

typedef struct runner_s {
    spritesheet_t *menu_bg;
    spritesheet_t *menu_start;
    spritesheet_t *menu_exit;
    spritesheet_t *character_bg;
    spritesheet_t *character_home;
    spritesheet_t *game_background1;
    spritesheet_t *game_background2;
    spritesheet_t *character_ichigo;
    spritesheet_t *character_toshiro;
    spritesheet_t *ichigo_run;
    spritesheet_t *ichigo_jump;
    spritesheet_t *toshiro_run;
    spritesheet_t *toshiro_jump;
    spritesheet_t *parralax_one;
    spritesheet_t *parralax_two;
    spritesheet_t *win_back;
    spritesheet_t *lose_back;
    spritesheet_t *quit;

    sfEvent event;
    sfMusic *ost;
    int scene;
    int jump;
    sfRenderWindow *window;
    sfVideoMode video_mode;
    float sec_ichigo;
    float sec_toshiro;
    sfTime time_ichigo;
    sfTime time_toshiro;
    sfClock *clock_ichigo;
    sfClock *clock_toshiro;
    int nb_sprite;
    int anti_jump;
    sfIntRect rect;
    int highscore;
    int x_movement;
    int y_movement;
    int score;
    int map_value;
    sfSoundBuffer *sound_jump_buffer;
    sfSound *sound_jump;
} runner_t;

// Utils and Map Management
spritesheet_t *image_creator(char *filename, sfVector2f position,
sfIntRect *rectangle, imageType_t type);
int clicked_button(spritesheet_t *image, int x, int y);

linked_list *load_map(char const *map, int x, int y);
linked_list *map_object(char const *map, linked_list *element, \
sfVector2f pos, int i);
char *open_map(char const *map_name);

// Event
runner_t *runner_event(runner_t *runner);
runner_t *runner_event_menu(runner_t *runner);

// Scene
void init_all_scene(runner_t *runner);
void main_scene(runner_t *menu);
void character_scene(runner_t *menu);
void game_scene_ichigo(runner_t *menu);
void game_scene_toshiro(runner_t *menu);

// Draw
void menu_draw(runner_t *menu);
void character_menu_draw(runner_t *menu);
void game_draw_ichigo(runner_t *runner, linked_list *game);
void game_draw_toshiro(runner_t *runner, linked_list *game);

// Animation
void animation_ichigo_run(sfSprite *sprite);
runner_t *animation_ichigo_jump(sfSprite *sprite, runner_t *runner);
void animation_toshiro_run(sfSprite *sprite);
runner_t *animation_toshiro_jump(sfSprite *sprite, runner_t *runner);
void ichigo_animation(runner_t *runner, linked_list *game);
void toshiro_animation(runner_t *runner, linked_list *game);

// Description
void description(void);

// Side Collision
int right_collision(spritesheet_t *character, spritesheet_t *map, float x);
int top_collision(spritesheet_t *character, spritesheet_t *map, float x);
int bottom_collision(spritesheet_t *character, spritesheet_t *map, float x);

// Collision Manager
runner_t *death_management_toshiro(runner_t *runner, linked_list *game);
runner_t *death_management_ichigo(runner_t *runner, linked_list *game);

// Game
void game_ichigo(runner_t *runner, linked_list *game);
void game_toshiro(runner_t *runner, linked_list *game);
void parralax_nbone(runner_t *runner);
void parralax_nbtwo(runner_t *runner);
void parralax_all(runner_t *runner);

void display_text(runner_t *runner, char *line, sfVector2f position);
int highscore_get(runner_t *runner);
int highscore_set(runner_t *runner);
void score_text(runner_t *runner);

void scene_management(runner_t *runner, linked_list *game);
int collision_manager(spritesheet_t *player, linked_list *map,
runner_t *runner);
void win_draw(runner_t *runner);
void lose_draw(runner_t *runner);
void win_scene(runner_t *runner);
void lose_scene(runner_t *runner);
int map_value(linked_list *map);

void destroy_one(runner_t *runner);
void destroy_all(sfSprite *sprite, sfTexture *texture);
void destroy_two(runner_t *runner);
