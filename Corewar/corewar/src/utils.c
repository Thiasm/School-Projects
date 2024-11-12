/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** utils.c
*/

int count_researched(char *str, char researched)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == researched) {
            j++;
        }
    }
    return j;
}

int reverse_int(int nb)
{
    int oct_a = nb & 0xFF;
    int oct_b = (nb >> 8) & 0xFF;
    int oct_c = (nb >> 16) & 0xFF;
    int oct_d = (nb >> 24) & 0xFF;

    return (oct_a * 16777216 + oct_b * 65536 + oct_c * 256 + oct_d);
}