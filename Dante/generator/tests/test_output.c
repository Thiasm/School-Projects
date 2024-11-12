/*
** EPITECH PROJECT, 2019
** test_output.c
** File description:
** output
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(my_putchar, first, .init = redirect_all_std)
{
    my_putchar('c');

    cr_assert_stdout_eq_str("c");
}

Test(my_putstr, first, .init = redirect_all_std)
{
    my_putstr("grattage de test unitaire");

    cr_assert_stdout_eq_str("grattage de test unitaire");
}
