/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define BUFF_SIZE 8

#define READ_SIZE 1024

void *my_memset(void *b, int c, size_t len);
void my_bzero(void *s, size_t n);
size_t my_strlen(const char *s);
size_t my_nbrlen(int n);
size_t my_strlcat(char *dst, const char *src, size_t size);
void *my_memalloc(size_t size);
char *my_strdup(const char *s1);
char *my_strndup(const char *s1, size_t len);
char *my_strcpy(char *dst, const char *src);
char *my_strncpy(char *dst, const char *src, size_t len);
char *my_strcat(char *s1, const char *s2);
char *my_strncat(char *s1, const char *s2, size_t n);
char *my_strstr(char *s1, const char *s2);
char *my_evil_str(char *str);
int exit_prog(int ret, char *str);
int *my_sort_int_tab(int *tab, int size);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
int my_isalpha(int c);
int my_isdigit(int c);
int my_isalnum(int c);
int my_isascii(int c);
int my_isprint(int c);
int my_getnbr(char *str);
int my_upper(int c);
int my_lower(int c);
int my_tablen(char **tab);
char *my_strnew(size_t size);
void my_strfree(char **str);
char *my_strsub(char const *s, unsigned int start, size_t len);
char *my_strjoin(char const *s1, char const *s2);
char *my_strtrim(char const *s);
char **my_strsplit(char const *s, char c);
char **my_strsplit_ws(char const *s1);
char *my_evil_str(char *str);
char *my_itoa(int n);
void my_putchar(char c);
void my_putstr(char const *s);
void my_put_nbr(long long int n);
void my_putchar_fd(char c, int fd);
void my_putstr_fd(char const *s, int fd);
void my_put_nbr_fd(int n, int fd);
void my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
int malloc_str_len(char const *str, int nbr);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_isspace(int c);
char *get_next_line(int const fd);
int my_count_char(char *str, char c);
char **my_tabdup(char **tab);
void my_freetab(char **tab);
int my_str_isnum(char const *str);
int my_sscmp(char *s, char *s1, char *s2);
int my_ssscmp(char *s, char *s1, char *s2, char *s3);
void my_putstrstr_fd(char *s1, char *s2, int fd);
int my_getnbr(char *str);

int my_printf(char *str, ...);
void arg_case_end(char arg, va_list ap, int j);
void arg_case_begin(char arg, va_list ap, int j);
void my_put_count(int *val, int j);
void my_put_base(long long int nbr, char *base);
void my_put_str_octal_calc(unsigned char nb);
void my_put_str_octal(char *str);
void my_put_add(long long int nbr);
void my_put_un_int(unsigned long long int nb);

#endif
