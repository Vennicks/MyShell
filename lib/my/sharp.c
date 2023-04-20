/*
** EPITECH PROJECT, 2018
** sharp
** File description:
** for printf's format
*/

#include "my.h"

void sharp(va_list list, int comp)
{
    if (comp == 'X') {
        my_putstr("0X");
        hexadecimal_maj(va_arg(list, unsigned int));
    } else if (comp == 'x') {
        my_putstr("0x");
        hexadecimal(va_arg(list, unsigned int));
    } else if (comp == 'o') {
        my_putchar('0');
        octal(va_arg(list, unsigned int));
    }
}