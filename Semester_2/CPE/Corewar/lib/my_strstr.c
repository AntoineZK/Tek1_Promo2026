/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** my_strstr
*/

#include "../include/corewar.h"

static int check_str(char *sub_string, char *full_string, int i)
{
    for (int j = 0; sub_string[j]; j++) {
        if (full_string[i + j] != sub_string[j])
            break;
        if (sub_string[j + 1] == '\0')
            return (1);
    }
    return (0);
}

int my_strstr(char *sub_string, char *full_string)
{
    int ret_value = 0;

    for (int i = 0; full_string[i]; i++) {
        ret_value = full_string[i] == sub_string[0] ?
        check_str(sub_string, full_string, i) : 0;
        if (ret_value == 1)
            return (1);
    }
    return (0);
}
