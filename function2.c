/*
** EPITECH PROJECT, 2018
** function2.c
** File description:
** functions of the minishell1
*/

#include "include/my.h"

char *suppr_point(char *str)
{
    int z = 2;
    int i = 0;
    char *str_wpoint = malloc(sizeof(char) * my_strlen(str) - 2);
    while (str[z] != '\0') {
        str_wpoint[i] = str[z];
        z++;
        i++;
    }
    return (str_wpoint);
}

int my_executable(char *str, char **env, char *file, int fd)
{
    char *slt = "hey";
    str = suppr_point(str);
    int pid = fork();
    char **command = my_str_to_wordtab(str, ' ');
    int status;
    if (access(command[0], X_OK) != 0) {
        write(2, "./", 2);
        write(2, command[0], my_strlen(command[0]));
        write(2, ": Permission denied.\n", 21);
        return (84);}
    if (pid == -1) {
        exit(0);
    } else if (pid == 0) {
        execve(command[0], command, env);
        while (str != NULL && fd != 0) write(fd, slt, my_strlen(str));
        exit(0);
    } else {
        pid = waitpid(pid, &status, 0);}
}

char *my_gethome(char **env, char *HOME)
{
    int d = 0;
    int z = 0;
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M' &&
        env[i][3] == 'E' && env[i][4] == '=') {
            d = i;
        }
    }
    for (int i = 5; env[d][i] != '\0'; i++) {
        HOME[z] = env[d][i];
        z++;
    }
    return (HOME);
}