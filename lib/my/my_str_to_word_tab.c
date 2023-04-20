/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_str_to_word_tab
*/

#include "my.h"

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;
    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n < i)
        dest[i] = '\0';
    return (dest);
}

int is_alnum2(char c, char car)
{
    if (c <= car || c >= 127) return (0);
    return (1);
}

int word_count2(char *str, char car)
{
    int i = 0;
    int word = 0;
    while (str != NULL && str[i]) {
        if (is_alnum2(str[i], car) == 1 && is_alnum2(str[i + 1], car) == 0)
            word = word + 1;
        ++i;
    }
    return (word);
}

char **my_str_to_wordtab2(char *str, char car)
{
    int j = 0;
    int i = 0;
    char **tab;
    int len = 0;
    tab = malloc(sizeof(char *) * (word_count2(str, car) + 1));
    while (str != NULL && str[i]) {
        if (is_alnum2(str[i], car)) len++;
        if (is_alnum2(str[i], car) == 1 && is_alnum2(str[i + 1], car) == 0) {
            tab[j] = malloc(sizeof(char) * (len + 1));
            my_strncpy(tab[j], &str[i - len + 1], len);
            len = 0;
            j++;
        }
        i++;
    }
    tab[j] = NULL;
    return (tab);
}