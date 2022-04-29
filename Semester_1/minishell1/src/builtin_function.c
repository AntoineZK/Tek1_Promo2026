/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
** File description:
** builtin_function
*/

#include "../include/my.h"
#include "../include/minishell.h"

void chdir_return (minishell_t *shell, char *path)
{
    if (chdir(path) == -1) {
        my_puterror(shell->cmd[1]);
        my_puterror(path);
        my_puterror(": No such file or directory\n");
    }
}

char **cd_function(minishell_t *shell)
{
    char *new_pwd = NULL;
    int index = 0;
    char **back = NULL;
    shell->old_pwd = getcwd(NULL, 0);
    if (shell->nb_words == 1) {
        chdir_return (shell, shell->home[1]);
    } else {
        if (my_strlen(shell->cmd[1]) == 1 &&
        my_strcmp(shell->cmd[1], "-") == 0) {
            chdir_return (shell, "/");
            back = my_str_to_word_array(getenv_function(shell, "OLDPWD"));
            chdir_return (shell, back[1]);
        } else {
            chdir_return (shell, shell->cmd[1]);
        }
    }
    shell->env = update_oldpwd(shell);
    shell->env = update_pwd(shell, new_pwd, index);
    return (shell->env);
}
