/*
** EPITECH PROJECT, 2018
** function.c
** File description:
** function of the minishell1
*/

#include "include/my.h"

void cd_function(char *str, char **env)
{
    char *path;
    int stateAccess;
    int space = 2;
    path = malloc(sizeof(char) * (my_strlen(str) - space));
    while (str[space] == ' ' || str[space] == '\t') {
        space++;
    }
    path = return_path(path, str, space, env);
    stateAccess = chdir(path);
    if (stateAccess == -1) {
        write(2, "cd: no such file or directory: ", 31);
        my_printf("%s\n", path);
    }
}

char **my_getenv(char **env)
{
    char **PATH;
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
        env[i][3] == 'H' && env[i][4] == '=') {
            PATH = my_str_to_wordtab(env[i], ':');
            return (PATH);
        }
    }
}

void my_execute(char *path_cat, char **env, char **command)
{
    int pid = fork();
    int status;
    if (pid == -1) {
        exit(0);
    } else if (pid == 0) {
        execve(path_cat, command, env);
        exit(0);
    } else {
        pid = waitpid(pid, &status, 0);
    }
}

void my_cat_pathexec(char **env, char *str)
{
    int z = 0;
    char **PATH = my_getenv(env);
    char **command = my_str_to_wordtab(str, ' ');
    char *path_cat;
    char *path_command;
    for (int i = 0; PATH[i] != NULL; i++) {
        path_cat = my_strcat(PATH[i], "/");
        path_command = my_strcat(path_cat, command[0]);
        if (access(path_command, X_OK) == 0) {
            z = 1;
            my_execute(path_cat, env, command);
            return;
        }
    }
    if (z == 0) {
        write(2, command[0], my_strlen(command[0]));
        write(2, ": Command not found.\n", 21);
    }
}

char *get_strwspace(char *str)
{
    int z = 0;
    int i = 0;
    char *wspace = malloc(sizeof(char) * my_strlen(str));
    while (str[z] == ' ' || str[z] == '\t')
        z++;
    while (str[z] != '\0') {
        wspace[i] = str[z];
        if (wspace[i] == '\t')
            wspace[i] = ' ';
        z++;
        i++;
    }
    return (wspace);
}