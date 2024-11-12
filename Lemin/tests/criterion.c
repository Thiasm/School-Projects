/*
** EPITECH PROJECT, 2019
** printf
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello  world");
    cr_assert_stdout_eq_str("hello  world");
}

Test(my_printf, simple_return, .init = redirect_all_std)
{
    my_printf("hello world\n");
    cr_assert_stdout_eq_str("hello world\n");
}

Test(my_printf, complex_return, .init = redirect_all_std)
{
    my_printf("Do\nYou\nWant\nCoca\nCola\n");
    cr_assert_stdout_eq_str("Do\nYou\nWant\nCoca\nCola\n");
}

Test(my_printf , simple_number, .init = redirect_all_std)
{
    my_printf("42");
    cr_assert_stdout_eq_str("42");
}

Test(my_printf , simple_string_s, .init = redirect_all_std)
{
    my_printf("%s", "hello world");
    cr_assert_stdout_eq_str("hello world");
}
