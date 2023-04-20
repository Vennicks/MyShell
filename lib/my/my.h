/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Write your my.h header file that contains the prototypes of library
*/
#ifndef MY_H
# define MY_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <SFML/Audio.h>
#include <signal.h>

int count_word(char *str, char c);
int countchar(char *str, char car);
char **my_str_to_wordtab(char *str, char car);
char *re_alloc(char *str);
char *get_next_line(const int fd);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *src);
int my_str_isum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_filelen(char *str);
int modulo(int nb, int d);
int octal(unsigned int comp);
void hexadecimal(unsigned int comp);
int binary(unsigned int comp);
char *clear_string(char *str);
int error_flags(char *str);
int my_putstr_mod(char *str);
void hexadecimal_maj(unsigned int comp);
int my_put_nbr_unsigned(unsigned int nb);
int modulo2(unsigned int nb, unsigned int d);
int characters(int type, va_list list, int comp);
int characters_2(int type, va_list list, int comp);
int characters_3(int type, va_list list, int comp);
int characters_4(int type, va_list list, int comp);
void minus_or_not(va_list list);
void sharp(va_list list, int comp);
int my_printf(const char *str, ...);
int my_putstr(char const *str);
char *my_revstr(char *str);
int pointer(int p);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(char const *str);
#endif