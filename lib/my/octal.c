/*
** EPITECH PROJECT, 2018
** octal.c
** File description:
** display an int converted into an octal base
*/

#include "my.h"


int octal(unsigned int comp)
{
    char *hexa = malloc(sizeof(char) * 15);
    int x = 0;
    int cmpt;
    while (comp != 0) {
        cmpt = 0;
        cmpt = comp % 8;
        hexa[x] = cmpt + 48;
        x++;
        comp = comp / 8;
    }
    my_putstr(my_revstr(hexa));
}