/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** callbacks
*/

#ifndef CALLBACKS_H_
    #define CALLBACKS_H_

    #include "rpg.h"

typedef struct func_dict {
    char *key;
    int (*value) (char **);
} func_dict;

int unload_scene(char **args);
int load_scene(char **args);
int exit_scene(char **args);
int load_game(char **args);
func_dict callback_from_name(char const *name);
scene *get_scene(char const *name);
int set_key(char **args);
int increase_volume(char **args);
int decrease_volume(char **args);
int increase_resolution(char **args);
int decrease_resolution(char **args);
int validate_resolution(char **args);

#endif/* !CALLBACKS_H_ */
