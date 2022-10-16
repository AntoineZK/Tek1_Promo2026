/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** arg_handler
*/

#include "../include/corewar.h"

static int helper(char *prog, int ret_val)
{
    my_printf("USAGE:\n%s [-dump nbr_cycle] [[-n prog_number] ", prog);
    my_printf("[-a load_address] prog_name]\n");
    my_printf("DESCRIPTION:\n-dump nbr_cycle dumps the memory after the ");
    my_printf("nbr_cycle execution (if the round isn’t already over) with ");
    my_printf("the following format: 32 bytes/line in hexadecimal ");
    my_printf("(A0BCDEFE1DD3...)\n-n prog_number sets the next program’s ");
    my_printf("number. By default, the first free number in the parameter ");
    my_printf("order\n-a load_address sets the next program’s loading ");
    my_printf("address. When no address is specified, optimize the ");
    my_printf("addresses so that the processes are as far away from");
    my_printf("each other as possible. The addresses are MEM_SIZE modulo.\n");
    return (ret_val);
}

int arg_n(corewar_t *g, char **av, int i)
{
    if (my_str_is_num(av[i + 1])) {
        i++;
        g->tmp_nb_player = my_atoi(av[i]);
    } else if (my_str_is_alpha_num(av[i + 1]))
        return (-1);
    return (i);
}

int arg_a(corewar_t *g, char **av, int i)
{
    if (my_str_is_num(av[i + 1])) {
        i++;
        g->load_adress = my_atoi(av[i]);
    } else if (my_str_is_alpha_num(av[i + 1]))
        return (-1);
    return (i);
}

static int dump(corewar_t *g, char **av, int i)
{
    if (my_strcmp(av[i], "-dump")) {
        if (my_str_is_num(av[i + 1]) && my_atoi(av[i + 1]) > 0) {
            g->nb_cycle = my_atoi(av[i + 1]);
            return (1);
        } else {
            return (helper(av[0], 84));
        }
    }
    return (1);
}

int arg_handler(corewar_t *g, int ac, char **av)
{
    g->tmp_nb_player = -1;
    if (ac == 2 && my_strcmp(av[1], "-h"))
        return (helper(av[0], 0));
    if (ac <= 2)
        return (helper(av[0], 84));
    for (int i = 1; i < ac; i++) {
        if (dump(g, av, i) == 84)
            return (84);
        i = arg_list_handler(g, av, i);
        if (i == -1)
            return (helper(av[0], 84));
    }
    return (1);
}
