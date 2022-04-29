/*
** EPITECH PROJECT, 2021
** B-PSU-101-NCY-1-1-navy-antoine.khalidy
** File description:
** navy_main
*/

#include "../include/my.h"
#include "../include/navy.h"

navy_t *navy;

void navy_management(int signals, siginfo_t *info, void *unknow)
{
    UNUSED(unknow);
    if (navy->started) {
        if (signals == 10 && navy->last_signal == 12) {
            navy->position_received = 1;
        } else if (signals == 10) {
            navy->x++;
            (navy->x > 8) ? navy->started = 0 : 0;
        }
        if (signals == 12) {
            navy->y++;
        }
        navy->last_signal = signals;
    } else {
        navy->identity = signals;
        navy->pid = info->si_pid;
    }
}

int second_player(char **argv)
{
    char *buffer;
    if ((buffer = open_file(argv[2])) == NULL)
        return (84);
    ship *ships = load_ships(buffer);
    if (ships == NULL)
        return (84);
    pid_t pid2 = getpid();
    kill(my_getnbr(argv[1]), SIGUSR1);
    my_putstr("my_pid: ");
    my_put_nbr(pid2);
    my_putchar('\n');
    if (navy->identity == SIGUSR2) {
        my_putstr("successfully connected\n");
        navy->started = 1;
        return (game_loop(ships));
    } else {
        my_putstr("wrong pid\n");
        return (84);
    }
    return (0);
}

int first_player(char **argv)
{
    char *buffer;
    if ((buffer = open_file(argv[1])) == NULL)
        return (84);
    ship *ships = load_ships(buffer);
    if (ships == NULL)
        return (84);
    pid_t pid1 = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(pid1);
    my_putchar('\n');
    my_putstr("waiting for enemy connection...");
    while (navy->identity == -1);
    kill(navy->pid, SIGUSR2);
    my_putstr("\n\nenemy connected\n");
    navy->started = 1;
    return (game_loop(ships));
}

int main(int argc, char **argv)
{
    struct sigaction navy_signals;
    navy = malloc(sizeof(navy_t));
    navy->started = 0;
    navy->identity = -1;
    navy_signals.sa_flags = SA_SIGINFO;
    navy_signals.sa_sigaction = navy_management;
    sigaction(SIGUSR1, &navy_signals, NULL);
    sigaction(SIGUSR2, &navy_signals, NULL);
    if (argc == 1) {
        my_puterror("./navy: missing arguments\n");
        return (84);
    } else if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        description();
    if (argc == 3) {
        return (second_player(argv));
    } else if (argc == 2)
        return (first_player(argv));
    return (0);
}
