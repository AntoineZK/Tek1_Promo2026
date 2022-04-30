/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
** File description:
** utils
*/

#include "../include/my.h"
#include "../include/minishell.h"

char **unsetenv_bis(minishell_t *shell, char *env_name, int index)
{
    if (my_strcmp(env_name, "NotInEnv") == 0) {
    } else {
        for (; shell->env[index]; index++) {
            shell->env[index] = shell->env[index + 1];
        }
    }
    return (shell->env);
}

char **update_pwd(minishell_t *shell, char *new_pwd, int index)
{
    new_pwd = getcwd(shell->buffer, 0);
    index = getenv_index(shell , "PWD");
    shell->env[index] = "";
    shell->env[index] = my_strcat("PWD", "=");
    shell->env[index] = my_strcat(shell->env[index], new_pwd);
    return (shell->env);
}

char **update_oldpwd(minishell_t *shell)
{
    char *old_name = getenv_function(shell, "OLDPWD");
    int old_index = getenv_index(shell, "OLDPWD");
    char *str = NULL;
    int i = 0;

    if (my_strcmp(old_name, "NotInEnv") == 0) {
        str = my_strcat("OLDPWD", "=");
        str = my_strcat(str, shell->old_pwd);
        for (; shell->env[i]; i++);
        shell->env[i] = str;
        shell->env[i + 1] = '\0';
    } else {
        shell->env[old_index] = "";
        shell->env[old_index] = my_strcat("OLDPWD", "=");
        shell->env[old_index] = my_strcat(shell->env[old_index],\
        shell->old_pwd);
    }
    return (shell->env);
}

char **setenv_bis_two(minishell_t *shell)
{
    char *env_name = getenv_function(shell, shell->cmd[1]);
    int index = getenv_index(shell, shell->cmd[1]);
    char *str = NULL;
    int i = 0;

    if (shell->cmd[1][0] >= '0' && shell->cmd[1][0] <= '9')
        return (shell->env);
    if (my_strcmp(env_name, "NotInEnv") == 0) {
        str = my_strcat(shell->cmd[1], "=");
        for (; shell->env[i]; i++);
        shell->env[i] = str;
        shell->env[i + 1] = '\0';
    } else {
        shell->env[index] = "";
        shell->env[index] = my_strcat(shell->cmd[1], "=");
    }
    return (shell->env);
}

char **setenv_bis_three(minishell_t *shell)
{
    char *env_name = getenv_function(shell, shell->cmd[1]);
    int index = getenv_index(shell, shell->cmd[1]);
    char *str = NULL;
    int i = 0;

    if (shell->cmd[1][0] >= '0' && shell->cmd[1][0] <= '9')
        return (shell->env);
    if (my_strcmp(env_name, "NotInEnv") == 0) {
        str = my_strcat(shell->cmd[1], "=");
        str = my_strcat(str, shell->cmd[2]);
        for (; shell->env[i]; i++);
        shell->env[i] = str;
        shell->env[i + 1] = '\0';
    } else {
        shell->env[index] = "";
        shell->env[index] = my_strcat(shell->cmd[1], "=");
        shell->env[index] = my_strcat(shell->env[index], shell->cmd[2]);
    }
    return (shell->env);
}
