/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
** File description:
** env_function
*/

#include "../include/my.h"
#include "../include/minishell.h"

char *getenv_function(minishell_t *shell, char *name_research)
{
    int i = 0;
    int len_name = my_strlen(name_research);
    for (; shell->env[i]; i++) {
        if (my_strncmp(name_research, shell->env[i], len_name) == 0)
            break;
    }
    if (shell->env[i] == NULL)
        return ("NotInEnv");
    return (shell->env[i]);
}

int getenv_index(minishell_t *shell, char *name_research)
{
    int i = 0;
    int len_name = my_strlen(name_research);
    for (; shell->env[i]; i++) {
        if (my_strncmp(name_research, shell->env[i], len_name) == 0)
            break;
    }
    return (i);
}

int env_function(minishell_t *shell)
{
    for (int i = 0; shell->env[i]; i++) {
        my_putstr(shell->env[i]);
        my_putchar('\n');
    }
    return (0);
}

char **setenv_function(minishell_t *shell)
{
    if (shell->nb_words == 2) {
        shell->env = setenv_bis_two(shell);
    } else if (shell->nb_words == 3) {
        shell->env = setenv_bis_three(shell);
    } else
        my_putstr("setenv: Too many arguments.\n");
    return (shell->env);
}

char **unsetenv_function(minishell_t *shell)
{
    char *env_name = NULL;
    int index;

    for (int i = 1; i != shell->nb_words; i++) {
        env_name = getenv_function(shell, shell->cmd[i]);
        index = getenv_index(shell , shell->cmd[i]);
        shell->env = unsetenv_bis(shell, env_name, index);
    }
    return (shell->env);
}
