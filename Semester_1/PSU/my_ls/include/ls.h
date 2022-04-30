/*
** EPITECH PROJECT, 2021
** ls.h
** File description:
** ls.h
*/

#ifndef LS_H
    #define LS_H
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>

typedef struct ls_s {
    DIR *directory;
    struct dirent *dir;
} ls_t;

int flags(int argc, char **argv, ls_t *ls);
void total(ls_t *ls, char *str);
char *date(char *time);
void name_user(uid_t user, gid_t grp);
void perm(mode_t permission);
int ls_noflags_arg(ls_t *ls, int argc, char **argv);
void ls_noflags(ls_t *ls);
int ls_l_arg(int argc, char **argv, ls_t *ls);
void ls_l(char *str, ls_t *ls);

#endif
