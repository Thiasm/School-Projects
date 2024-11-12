/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** files for manage fight background chose management
*/

#include "rpg.h"

char *chose_background(int x, int y)
{
    if (x <= 143 && x >= 107 && y >= 2 && y <= 36)
        return("assets/fight_background/castle.png");
    if (x >= 82 && x <= 149 && y >= 0 && y <= 51)
        return("assets/fight_background/snow.png");
    if (x >= 114 && x <= 146 && y  >= 78 && y <=96)
        return("assets/fight_background/forest.png");
    if (x >= 58 && x <= 76 && y >= 56 && y <= 73)
        return("assets/fight_background/swamp.png");
    if (x >= 0 && x <= 81 && y >= 54 && y <= 99)
        return("assets/fight_background/desert.png");
    return("assets/fight_background/plaine.png");
}
