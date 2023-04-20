/*
** EPITECH PROJECT, 2018
** my_putstr_mod
** File description:
** display a string with ascii value.
*/

#include "my.h"
int nbr_zero(int comp)
{
    if (comp<8)
        my_putstr("00");
    else if (comp >= 8 && comp < 64)
        my_putchar('0');
}

int my_putstr_mod(char *str)
{
    int entier;
    int i = 0;
    while (str[i] != '\0' || (str[i+1] > '\7' && str[i+1] < 128)) {
        if (str[i] < 0)
            str[i] = str[i] * (-1);
        if (str[i] < 127 && str[i] > 32) {
            my_putchar(str[i]);
        } else {
            my_putchar('\\');
            nbr_zero(str[i]);
            octal(str[i]);
        }
        i++;
    }
}