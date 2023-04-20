/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** function4
*/

#include "include/my.h"

void one_more(int exec, char **env, char *str)
{
    char *wrt = "hey";
    char **cmd =my_str_to_wordtab(str, '>');
    cmd[1] = get_strwspace(cmd[1]);
    cmd[1] = str_fin_wspace(cmd[1]);
    cmd[0] = get_strwspace(cmd[0]);
    cmd[0] = str_fin_wspace(cmd[0]);
    int fd = open(cmd[1], O_CREAT | O_RDWR, S_IRWXU);
    if (cmd[0] == NULL || cmd[1] == NULL)
        return;
    while (wrt != NULL) {
        str = get_next_line(0);
        write(fd, str, my_strlen(str));
    }
}

void two_more(int exec, char **env, char *str)
{
    char *wrt = "hey";
    int fd;
    char **cmd =my_str_to_wordtab(str, '>');
    if (cmd[0] == NULL || cmd[1] == NULL)
        return;
    cmd[1] = get_strwspace(cmd[1]);
    cmd[1] = str_fin_wspace(cmd[1]);
    fd = open(cmd[1], O_CREAT | O_RDWR, S_IRWXU);
    lseek(fd, 0, SEEK_END);
    write(fd, "\n", 1);
    cmd[0] = get_strwspace(cmd[0]);
    cmd[0] = str_fin_wspace(cmd[0]);
    test_cmd(env, cmd[0], cmd[1], fd);
}

int posi_one(int exec, char **env, char *str)
{
    int nb_more = 0;
    int nb_less = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        (str[i] == '>') ? nb_more++ : 0;
        (str[i] == '<') ? nb_less++ : 0;}
    if (nb_more == 1 && nb_less == 0)
        one_more(exec, env, str);
    if (nb_more == 2 && nb_less == 0);
    if (nb_more >= 3 && nb_less == 0)
        my_printf("Too much '>'\n");
    if (nb_less == 1 && nb_more == 0);
    if (nb_less == 2 && nb_more == 0);
    if (nb_less >= 3 && nb_more == 0)
        my_printf("To much '<'\n");
    if (nb_more != 0 && nb_less != 0)
        my_printf("Error with comparator\n");
    return (nb_more + nb_less);
}