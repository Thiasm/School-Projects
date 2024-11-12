/*
** EPITECH PROJECT, 2019
** criterion_lemin
** File description:
** CPE_lemin_2018
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

int check_if_tunnels(char *str);

Test(check_tunnels_1, check_normal)
{
    cr_assert_eq(check_if_tunnels("2-3\n"), 1);
}

Test(check_tunnels_2, check_normal_2)
{
    cr_assert_eq(check_if_tunnels("4-3\n"), 1);
}

Test(check_tunnels_3, check_room)
{
    cr_assert_eq(check_if_tunnels("34 55 2\n"), 0);
}

Test(check_tunnels_4, check_word)
{
    cr_assert_eq(check_if_tunnels("salut\n"), 0);
}

Test(check_tunnels_5, check_letter)
{
    cr_assert_eq(check_if_tunnels("A-3\n"), 1);
}

Test(check_tunnels_6, check_letter_2)
{
    cr_assert_eq(check_if_tunnels("A-B\n"), 1);
}

int check_if_room(char *str);

Test(check_rooms_1, check_normal)
{
    cr_assert_eq(check_if_room("1 2 3"), 1);
}

Test(check_rooms_2, check_normal_2)
{
    cr_assert_eq(check_if_room("5 9 3"), 1);
}

Test(check_rooms_3, check_tunnel)
{
    cr_assert_eq(check_if_room("3-9\n"), 0);
}

Test(check_rooms_4, check_word)
{
    cr_assert_eq(check_if_room("salut\n"), 0);
}

Test(check_rooms_5, check_missing)
{
    cr_assert_eq(check_if_room("5 9"), 0);
}

Test(check_rooms_6, check_tunnel_1)
{
    cr_assert_eq(check_if_room("5-9-3"), 0);
}

Test(check_rooms_7, check_normal_2)
{
    cr_assert_eq(check_if_room("A 5 3"), 1);
}