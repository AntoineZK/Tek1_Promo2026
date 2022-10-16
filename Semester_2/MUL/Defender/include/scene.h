/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** scene
*/

#ifndef SCENE_H_
    #define SCENE_H_
    #include "my.h"

typedef enum scene_s {
    MENU,
    GAME,
    SETTINGS,
    TUTO,
    PAUSE,
} scene_t;

typedef struct highlight_s {
    int sett_return;
    int start_light;
    int exit_light;
    int sett_light;
    int tuto_light;
    int tuto_return;
    int minus_light;
    int plus_light;
    int resume_light;
    int p_exit_light;
    int p_sett_light;
    int return_light;
} hg_t;

typedef struct image_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} image_t;

typedef struct map_t {
    image_t *value;
    struct map_t *next;
} map_t;

typedef struct menu_s {
    image_t *m_background;
    image_t *m_start;
    image_t *m_exit;
    image_t *m_sett;
    image_t *m_tuto;
    image_t *m_start_o;
    image_t *m_exit_o;
    image_t *m_sett_o;
    image_t *m_tuto_o;
} menu_t;

typedef struct game_s {
    image_t *g_background;
    image_t *g_fire_tow;
    image_t *g_stone_tow;
    image_t *g_slow_tow;
    image_t *g_obe_tow;
    image_t *g_moula_tow;
    image_t *g_redm_tow;
    image_t *g_heart;
    image_t *g_coin;
    image_t *g_upgrade;
} game_t;

typedef struct settings_s {
    image_t *s_background;
    image_t *s_return;
    image_t *s_return_o;
    image_t *s_plus_o;
    image_t *s_plus;
    image_t *s_minus;
    image_t *s_minus_o;
} settings_t;

typedef struct tuto_s {
    image_t *t_background;
    image_t *t_return;
    image_t *t_return_o;
} tuto_t;

typedef struct pause_s {
    image_t *p_background;
    image_t *p_return;
    image_t *p_resume;
    image_t *p_exit;
    image_t *p_sett;
    image_t *p_sett_o;
    image_t *p_return_o;
    image_t *p_resume_o;
    image_t *p_exit_o;
} pause_t;

#endif
