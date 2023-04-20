/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** task3
*/
#include "my.h"


char *my_revstr(char *str)
{
    int i;
    int len;
    char c;

    len = my_strlen(str);
    i = 0;
    while (i < len / 2) {
        c = *(str + i);
        *(str + i) = *(str + len - i - 1);
        *(str + len - i - 1) = c;
        ++i;
    }
    return (str);
}
