/*
** EPITECH PROJECT, 2021
** lsflags
** File description:
** lsflags
*/

#include "../include/my.h"
#include "../include/ls.h"

int flags(int argc, char **argv, ls_t *ls)
{
    if (argc == 2) {
        switch (argv[1][1]) {
        case 'l' :
            ls_l("./", ls);
            break;
        }
    } else {
        switch (argv[1][1]) {
        case 'l' :
            ls_l_arg(argc, argv, ls);
            break;
        default:
            break;
        }
    }
    return (0);
}
