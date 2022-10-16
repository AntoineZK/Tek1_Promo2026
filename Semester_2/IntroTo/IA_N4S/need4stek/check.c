/*
** EPITECH PROJECT, 2022
** need4stek
** File description:
** check
*/

#include "my.h"

int is_end(char *end)
{
    char *new = malloc(sizeof(char *) * (strlen(end) + 1));

    new = strcpy(new, end);
    new = strtok(new, ":");
    new = strtok(NULL, ":");
    new = strtok(NULL, ":");
    new = strtok(NULL, ":");
    if (strcmp("Track Cleared", new) == 0) {
        printf("STOP_SIMULATION\n");
        return (1);
    }
    return (0);
}

char *clean_lidar(char *str)
{
    int i = 0;
    int j = 0;
    char *tmp = malloc(sizeof(char *) * (strlen(str) + 1));

    for (; i != 3; j++) {
        if (str[j] == ':')
            i++;
    }
    i = 0;
    for (; str[j] != '\0'; j++) {
        if ((str[j] >= '0' && str[j] <= '9') ||
            str[j] == '.' || str[j] == ':') {
            tmp[i] = str[j];
            i++;
        }
    }
    tmp[i - 1] = '\0';
    return (tmp);
}
