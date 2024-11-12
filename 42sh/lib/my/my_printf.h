/*
** EPITECH PROJECT, 2018
** my_printf.h
** File description:
** .h for my_printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int my_strlen(char *str);

void my_putchar(char c);

void my_putstr(char *str);

void my_put_nbr(long long int nb);

void my_put_un_int(unsigned long long int nb);

void arg_case_end(char arg, va_list ap, int j);

void my_put_count(int *val, int j);

void my_put_base(long long int nbr, char *base);

void my_put_str_octal_calc(unsigned char nb);

void my_put_str_octal(char *str);

void my_put_add(long long int nbr);

int my_printf(char *str, ...);

#endif /* MY_PRINTF_H_ */
