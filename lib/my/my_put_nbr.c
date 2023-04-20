/*
** EPITECH PROJECT, 2018
** my_print_nbr
** File description:
** disp the number asked
*/
#include "my.h"

int my_put_nbr(int nb)
{
    int d;
    if (nb == -2147483648) {
        write(1, "-2147483648", 12);
    } else {
        if (nb < 0) {
            my_putchar('-');
            nb = nb * -1;
        }
        modulo(nb, d);
    }
}

int modulo(int nb, int d)
{
    if (nb >= 10) {
        d = nb % 10;
        nb = (nb - d) / 10;
        my_put_nbr(nb);
        my_putchar((d % 10) + 48);
    } else {
        my_putchar(nb + 48);
        return (0);
    }
}
