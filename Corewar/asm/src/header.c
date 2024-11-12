/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** header.c
*/

#include "asm.h"

char *concat_header(char *s1, const char *s2, int m)
{
    int n;
    int i = m;
    int j = my_strlen(s1);

    for (n = 0; s2[n] != '\"'; n++) {
        if (s2[n] == '\0') {
            exit_prog(false, "error: no '\"' after name or comment.");
            return NULL;
        }
    }
    while (s2[j] && j < n) {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    return (s1);
}

bool is_header(header_t *hd, char *line)
{
    int i;

    if (!line)
        return false;
    for (i = 0; my_isspace(line[i]); i++);
    if (!my_strncmp(&line[i], NAME_CMD_STRING, my_strlen(NAME_CMD_STRING))) {
        for (i = 0; line[i] != '\"'; i++)
            if (line[i] == '\0')
                return exit_prog(false, "error: no '\"' before prog name.");
        if (concat_header(hd->prog_name, &line[i + 1], 4) == NULL)
            return false;
    } else if (!my_strncmp(&line[i], COMMENT_CMD_STRING,
        my_strlen(COMMENT_CMD_STRING))) {
        for (i = 0; line[i] != '\"'; i++)
            if (line[i] == '\0')
                return exit_prog(false, "error: no '\"' before comment.");
        if (concat_header(hd->comment, &line[i + 1], 0) == NULL)
            return false;
    } else
        return false;
    return true;
}
