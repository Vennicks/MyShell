/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** Write a function that returns the square root 
*/
#include "my.h"

int my_compute_square_root(int nb)
{
    int cp = 1;
    int p = 1;
    while (1) {
        cp = p * p;
        if (cp == nb) {
            return (p);
        }
        if (cp > nb) {
            return (0);
        }
        p++;
    }
}
