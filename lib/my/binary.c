/*
** EPITECH PROJECT, 2018
** binary
** File description:
** display an int converted into a binary
*/

#include "my.h"

int binary(unsigned int comp)
{
    char *hexa = malloc(sizeof(char) * 15);
    int x = 0;
    int cmpt;
    while (comp != 0) {
        cmpt = 0;
        cmpt = comp % 2;
        hexa[x] = cmpt + 48;
        x++;
        comp = comp / 2;
    }
    my_putstr(my_revstr(hexa));
}