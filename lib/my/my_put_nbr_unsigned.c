/*
** EPITECH PROJECT, 2018
** my_put_nbr_unsigned
** File description:
** display a string witch the ascii value if they can"t be displaid
*/
#include "my.h"

int modulo2(unsigned int nb, unsigned int d)
{
    if (nb >= 10) {
        d = nb % 10;
        nb = (nb - d) / 10;
        my_put_nbr_unsigned(nb);
        my_putchar((d % 10) + 48);
    } else {
        my_putchar(nb + 48);
        return (0);
    }
}

int my_put_nbr_unsigned(unsigned int nb)
{
    unsigned int d;
    if (nb == -2147483648) {
        write(1, "-2147483648", 12);
    } else {
        if (nb < 0) {
            my_putchar('-');
            nb = nb * -1;
        }
        modulo2(nb, d);
    }
}

