/*
** EPITECH PROJECT, 2019
** test.c
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../my.h"

char *my_malloc(char *str, int size);
int my_strcmp(char *string, char *str);
char *my_strcpy(char *str);


Test(my_strcmp, cmp)
{
    char *str = "ah";
    char *other = "ah";

    cr_assert_eq(my_strcmp(str, other), 1);
}

Test(my_strcpy, cpy)
{
    char *str = "test";
    char *ret = malloc(sizeof(char) * 100);

    ret = my_strcpy(str);
    cr_assert_str_eq(ret, "test\0");
}

Test(my_malloc, malloc)
{
    char *str = "";
    char *ret = malloc(sizeof(char) * 100);

    ret = my_malloc(str, 4);
    cr_assert_str_eq(ret, "");
}
