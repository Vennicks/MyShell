/*
** EPITECH PROJECT, 2018
** character
** File description:
** flags of printf
*/

#include "my.h"

void minus_or_not(va_list list)
{
    int b = va_arg(list, int);
    if (b < 0)
        my_put_nbr(b);
    else if (b >= 0) {
        my_putchar('+');
        my_put_nbr(b);
    }
}

int characters_4(int type, va_list list, int comp)
{
    switch (type) {
    case '-':
        characters(comp, list, 0);
        return (1);
    case '+':
        if (comp == 'd' || comp == 'i') {
            minus_or_not(list);
        }
        return (1);
    case '#':
        sharp(list, comp);
        return (1);
    default:
        my_putchar('%');
        my_putchar(type);
        return (0);
    }
}

int characters_3(int type, va_list list, int comp)
{
    switch (type) {
    case 's':
        my_putstr(va_arg(list, char *));
        return (0);
    case 'u':
        my_put_nbr_unsigned(va_arg(list, unsigned int));
        return (0);
    case 'p':
        pointer(va_arg(list, int));
        return (0);
    default:
        return (characters_4(type, list, comp));
    }
}

int characters_2(int type, va_list list, int comp)
{
    switch (type) {
    case 'o':
        octal(va_arg(list, int));
        return (0);
    case 'x':
        hexadecimal(va_arg(list, unsigned int));
        return (0);
    case '%':
        my_putchar('%');
        return (0);
    case 'X':
        hexadecimal_maj(va_arg(list, unsigned int));
        return (0);
    default:
        return (characters_3(type, list, comp));
    }
}

int characters(int type, va_list list, int comp)
{
    switch (type) {
    case 'd':
        my_put_nbr(va_arg(list, int));
        return (0);
    case 'i':
        my_put_nbr(va_arg(list, int));
        return (0);
    case 'c':
        my_putchar(va_arg(list, char *));
        return (0);
    case 'S':
        my_putstr_mod(va_arg(list, char *));
        return (0);
    case 'b':
        binary(va_arg(list, unsigned int));
        return (0);
    default:
        return (characters_2(type, list, comp));
    }
}