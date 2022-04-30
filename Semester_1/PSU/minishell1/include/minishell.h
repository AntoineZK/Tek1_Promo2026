/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
** File description:
** minishell
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

typedef struct minishell_s {
    char *term;
    size_t size_term;
    int nb_words;
    char **cmd;
    char *buffer;
    char **home;
    char **env;
    char *path;
    char *old_pwd;
} minishell_t;

#endif

void description(void);
int env_function(minishell_t *shell);
char *getenv_function(minishell_t *shell, char *name_research);
char **setenv_function(minishell_t *shell);
char **unsetenv_function(minishell_t *shell);
char **unsetenv_bis(minishell_t *shell, char *env_name, int index);
char **cd_function(minishell_t *shell);
int generic_function(minishell_t *shell);
int choice_function(minishell_t *shell);
int getenv_index(minishell_t *shell, char *name_research);
char **update_pwd(minishell_t *shell, char *new_pwd, int index);
char **update_oldpwd(minishell_t *shell);
char **setenv_bis_two(minishell_t *shell);
char **setenv_bis_three(minishell_t *shell);
int generic_bis(minishell_t *shell, char *command, int status);
