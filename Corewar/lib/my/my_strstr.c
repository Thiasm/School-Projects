/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** find a needle in a haystack
*/

char *my_strstr(char *str, char const *to_find)
{
    int find_len;

    if (to_find[0] == '\0')
        return (str);
    for (int i = 0; str[i] != '\0'; i++) {
        find_len = 0;
        while (to_find[find_len] == str[i + find_len]) {
            if (to_find[find_len] != '\0' && to_find[find_len + 1] == '\0') {
                return (&str[i]);
            } else if (str[i] == '\0') {
                return (0);
            }
            find_len++;
        }
        i++;
    }
    return (0);
}
