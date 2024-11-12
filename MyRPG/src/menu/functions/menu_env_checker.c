/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** No description
*/

#include "rpg.h"
#include <stdbool.h>

bool my_strcmp_path(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '='; i++) {
        if (s1[i] != s2[i])
            return (false);
    }
    return (true);
}

char *my_getenv(char **envp, char *to_compare)
{
    char **env = envp;
    char *current_env;

    for (; *env != 0; env++) {
        if (my_strcmp_path(*env, to_compare) == 1) {
            current_env = *env;
            while (*current_env != '=')
                current_env++;
            current_env++;
            if (*current_env == '\0')
                return (NULL);
            return (current_env);
        }
    }
    return (NULL);
}