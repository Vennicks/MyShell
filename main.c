/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main of the minishell1
*/

#include "./include/my.h"

char *return_path(char *path, char *str, int space, char **env)
{
    int z = 0;
    int p = 0;
    int i = 0;
    char *HOME = malloc(sizeof(char) * 1000);
    while (str[space] != '\0') {
        path[z] = str[space];
        space++;
        z++;
        i = 1;
    }
    path[z] = '\0';
    if ((i != 1) || ((path[0] == '-' && path[1] == '-') && (path[2] == ' ' ||
    path[2] == '\t' || path[2] == '\0'))) {
        path = my_gethome(env, HOME);
        path[my_strlen(path)] = '\0';
    }
    return (path);
}

void ext(char *str)
{
    if (str == NULL)
        return;
    char test[5] = "exit\0";
    int i = 0;
    while (i != 5) {
        if (str[i] != test[i])
            return;
        i++;
    }
    my_printf("exit\n");
    exit(0);
}

int loop_sh(char **env, char *str)
{
    int nb_similicons;
    while (1) {
        my_printf("\033[31m(master)> \033[0m");
        str = get_next_line(0);
        nb_similicons = similicons_count(str);
        if (str != NULL && str[0] != '\0' && nb_similicons == 0) {
            str = get_strwspace(str);
            str = str_fin_wspace(str);
            test_cmd(env, str, NULL, 0);
            clear_string(str);}
        if (str != NULL && str[0] != '\0' && nb_similicons > 0)
            handle_similicons(str, nb_similicons, env);
        if (str == NULL) {
            write(1, "exit\n", 5);
            exit(0);}}
}

int main(int argc, char **argv, char **env)
{
    if (argc != 1)
        return (0);
    char *str = malloc(sizeof(char) * 100000);
    if (argc != 1)
        return (84);
    loop_sh(env, str);
}