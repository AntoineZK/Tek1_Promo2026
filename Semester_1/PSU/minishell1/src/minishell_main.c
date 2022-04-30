/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
** File description:
** minishell_main
*/

#include "../include/my.h"
#include "../include/minishell.h"

minishell_t *init_struct(minishell_t *shell, char **envp)
{
    shell->term = NULL;
    shell->size_term = 0;
    shell->nb_words = 0;
    shell->cmd = NULL;
    shell->buffer = NULL;
    shell->env = envp;
    shell->home = my_str_to_word_array(getenv_function(shell, "HOME"));
    shell->path = getenv_function(shell, "PATH");
    shell->path = my_strcat(shell->path, ":./");
    return (shell);
}

int minishell_one(char **envp)
{
    minishell_t *shell = malloc(sizeof(minishell_t));
    shell = init_struct(shell, envp);

    while (1) {
        signal(SIGINT, SIG_IGN);
        my_putstr("(]===[)===========> ");
        if (getline(&shell->term, &shell->size_term, stdin) == -1)
            break;
        if (shell->term[0] == '\n')
            continue;
        shell->nb_words = count_words(shell->term);
        shell->cmd = my_str_to_word_array(shell->term);
        if (choice_function(shell))
            break;
    }
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    if (argc == 2 || argc == 1) {
        return (minishell_one(envp));
    } else if (argv[1][0] == '-' && argv[1][1] == 'h') {
        description();
        return (0);
    } else {
        my_putstr("Invalid Argiment\n");
        return (84);
    }
}
