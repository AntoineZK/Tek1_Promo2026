/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myhunter-antoine.khalidy
** File description:
** myhunter
*/

#ifndef MYHUNTER_H_
    #define MYHUNTER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <time.h>
    #include <SFML/Window.h>
#endif

typedef struct spritesheet_s {
    sfSprite *sprite;
    sfSprite *sprite_copy;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
} spritesheet_t;

typedef struct text_s {
    sfText *txt;
    sfFont *font;
    sfColor color;
} text_t;

typedef struct hunter_s {
    spritesheet_t *menu_back;
    spritesheet_t *start;
    spritesheet_t *exit;
    spritesheet_t *difficulty_back;
    spritesheet_t *easy;
    spritesheet_t *normal;
    spritesheet_t *hard;
    spritesheet_t *home;
    spritesheet_t *game_back;
    spritesheet_t *link;
    spritesheet_t *goblin;
    spritesheet_t *wyvern;
    spritesheet_t *win_back;
    spritesheet_t *lose_back;

    sfEvent event;
    int scene;
    sfRenderWindow *window;
    sfVideoMode video_mode;
    float sec_monster;
    sfTime time_monster;
    sfClock *clock_monster;
    sfIntRect rect;
    int highscore;
    int score;
    int nb_life;
    sfMusic *zelda_ost;
    sfSound *zelda_bow;
    sfSoundBuffer *zelda_bow_buffer;
} hunter_t;

// Utils and Map Management
spritesheet_t *image_creator(char *filename, sfVector2f position,
sfIntRect *rectangle);
int clicked_button(spritesheet_t *image, int x, int y);
void moving_goblin(sfSprite *sprite);
void animation_goblin(sfSprite *sprite);
void moving_wyvern(sfSprite *sprite);
void animation_wyvern(sfSprite *sprite);
void description(void);
void menu_draw(hunter_t *hunter);
void difficulty_draw(hunter_t *hunter);
void easy_draw(hunter_t *hunter);
void normal_draw(hunter_t *hunter);
void hard_draw(hunter_t *hunter);
hunter_t *hunter_event(hunter_t *hunter);
hunter_t *hunter_event_menu(hunter_t *hunter);
hunter_t * kill_the_goblin(hunter_t *hunter);
hunter_t * kill_the_wyvern(hunter_t *hunter);
hunter_t *revive_goblin(hunter_t *hunter);
hunter_t *revive_wyvern(hunter_t *hunter);
int highscore_get(hunter_t *hunter);
int highscore_set(hunter_t *hunter);
void display_text(hunter_t *hunter, char *line, sfVector2f position, int i);
void score_text(hunter_t *hunter);
hunter_t *init_struct(hunter_t *hunter);
void hunter(void);
int main(int argc, char **argv);
void scene_management(hunter_t *hunter);
void main_scene(hunter_t *hunter);
void difficulty_scene(hunter_t *hunter);
void game_scene(hunter_t *hunter);
void init_all_scene(hunter_t *hunter);
hunter_t *revive_mobs(hunter_t *hunter);
hunter_t *kill_mobs(hunter_t *hunter);
void menu_text(hunter_t *hunter, int i);
void win_draw(hunter_t *hunter);
void lose_draw(hunter_t *hunter);
void final_scene(hunter_t *hunter);
void destroy_one(hunter_t *hunter);
void sfDestroy(sfSprite *sprite, sfTexture *texture);
void destroy_two(hunter_t *hunter);
