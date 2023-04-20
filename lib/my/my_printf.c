/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_printf
*/

#include "my.h"

int pointer(int p)
{
    my_putstr("0x");
    hexadecimal(p);
}

int my_printf(const char *str, ...)
{
    int error;
    int z = my_strlen(str);
    int b;
    va_list list;
    int s;
    va_start(list, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            i = i + characters(str[i+1], list, str[i+2]);
            i = i+1;
        } else {
            my_putchar(str[i]);
        }
    }
    va_end(list);
}