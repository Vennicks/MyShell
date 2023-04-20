/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** the lenght of a string
*/
#include "my.h"

int my_strlen(char const *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return (count);
}
