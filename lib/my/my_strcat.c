/*
** EPITECH PROJECT, 2018
** my_strcat 
** File description:
** my strcat
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int j;
    j = 0;
    i = my_strlen(dest);
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
