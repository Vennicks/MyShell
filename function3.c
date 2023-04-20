/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** function3
*/

#include "include/my.h"

void display_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);
}

void test_cmd(char **env, char *str, char *file, int fd)
{
    int exec = 0;
    ext(str);
    if (posi_one(exec, env, str) != 0)
        return;
    if ((str[0] == 'c' && str[1] == 'd') && (str[2] == ' ' ||
    str[2] == '\t' || str[2] == '\0')) {
        cd_function(str, env);
        exec = 1;}
    if (str == NULL)
        return;
    if (str[0] == 'e' && str[1] == 'n' && str[2] == 'v' && str[3]== '\0'){
        display_env(env);
        exec = 1;}
    if (str[0] == '.' && str[1] == '/') {
        if (fd == 0)
            my_executable(str, env, NULL, 0);
        else
            my_executable(str, env, str, fd);
        exec = 1;}
    if (exec != 1)
        my_cat_pathexec(env, str);
}

int similicons_count(char *str)
{
    int i = 0;
    if (str == NULL)
        return (0);
    for (int z = 0; str[z] != '\0'; z++) {
        if (str[z] == ';')
            i++;
    }
    return (i);
}

char *str_fin_wspace(char *str)
{
    int i = my_strlen(str) - 1;
    while (str[i] == ' ' || str[i] == '\t') {
        i--;
    }
    i++;
    while (str[i] != '\0') {
        str[i] = '\0';
        i++;}
    return (str);
}

void handle_similicons(char *str, int nb_similicons, char **env)
{
    char **command;
    command = malloc(sizeof(char *) * nb_similicons + 2);
    command = my_str_to_wordtab(str, ';');
    command[nb_similicons + 2] = NULL;
    for (int i = 0; command[i] != NULL; i++) {
        command[i] = get_strwspace(command[i]);
        command[i] = str_fin_wspace(command[i]);
        test_cmd(env, command[i], NULL, 0);
    }
    clear_string(str);
}