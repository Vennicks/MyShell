/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** clear_string
*/
#include "my.h"

char *clear_string(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = '\0';
    return (str);
}