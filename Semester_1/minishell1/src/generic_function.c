/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
** File description:
** generic_function
*/

#include "../include/my.h"
#include "../include/minishell.h"

void execve_return (char *command, minishell_t *shell)
{
    if (execve(command, shell->cmd, shell->env) == -1) {
        my_putstr(shell->cmd[0]);
        my_putstr(": Command not found.\n");
    }
}

int generic_bis(minishell_t *shell, char *command, int status)
{
    if (fork() != 0) {
        waitpid(-1, &status, 0);
    } else {
        execve_return (command, shell);
        exit(0);
    }
    return (status);
}

int generic_function(minishell_t *shell)
{
    int status = 0;
    char **str = my_str_to_word_array(shell->path);
    char *cmd_pwd = getcwd(NULL, 0);
    int i = 0;
    char *command = NULL;

    for (; str[i + 1]; i++) {
        command = (my_strcat(str[i + 1], "/"));
        command = (my_strcat(command, shell->cmd[0]));
        if (access(command, F_OK) == 0)
            break;
    }
    if (str[i + 1] == NULL) {
        command = my_strcat(cmd_pwd, "/");
        command = my_strcat(command, shell->cmd[0]);
    }
    status = generic_bis(shell, command, status);
    if (status == 139)
        my_putstr("Segmentation fault\n");
    return (0);
}
