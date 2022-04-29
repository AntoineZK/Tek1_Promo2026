/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
** File description:
** choice_function
*/

#include "../include/my.h"
#include "../include/minishell.h"

int choice_function(minishell_t *shell)
{
    if ((shell->nb_words == 1 || shell->nb_words == 2) &&
    my_strcmp(shell->cmd[0], "cd") == 0) {
        shell->env = cd_function(shell);
        return (0);
    }
    if (shell->nb_words == 1 && my_strcmp(shell->cmd[0], "env") == 0)
        return (env_function(shell));
    if (shell->nb_words == 1 && my_strcmp(shell->cmd[0], "exit") == 0)
        return (1);
    if (shell->nb_words >= 2 && my_strcmp(shell->cmd[0], "unsetenv") == 0){
        shell->env = unsetenv_function(shell);
        return (0);
    }
    if (my_strcmp(shell->cmd[0], "setenv") == 0) {
        shell->env = setenv_function(shell);
        return (0);
    } else
        return (generic_function(shell));
}
