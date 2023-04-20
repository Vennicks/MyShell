/*
** EPITECH PROJECT, 2018
** hexa
** File description:
** diplay an int converted into hexa 
*/

#include "my.h"

void hexadecimal(unsigned int comp)
{
    char *hexa = malloc(sizeof(char) * 15);
    int x = 0;
    int cmpt;
    while (comp != 0) {
        cmpt = 10;
        cmpt = comp % 16;
        if (cmpt < 10) {
            hexa[x] = cmpt + 48;
            x++;
        } else {
            hexa[x] = cmpt + 87;
            x++;
        }
        comp = comp /16;
    }
    my_putstr(my_revstr(hexa));
}