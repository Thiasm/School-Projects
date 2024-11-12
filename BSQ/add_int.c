/*
** EPITECH PROJECT, 2018
** add_in_int
** File description:
** bsq
*/

struct var_for_check_around
{
    int i;
    int j;
    int up_i;
    int left_up_i;
    int left_i;
};

typedef struct var_for_check_around token_t;

void check_around_if(int **tab_int, token_t var)
{
    if (var.left_i <= var.up_i && (var.left_i <= var.left_up_i))
        tab_int[var.i][var.j] += var.left_i;
    else if ((var.up_i <= var.left_i) && (var.up_i <= var.left_up_i))
        tab_int[var.i][var.j] += var.up_i;
    else
        tab_int[var.i][var.j] += var.left_up_i;
}

void check_around(int **tab_int, token_t var)
{
    if (tab_int[var.i][var.j] > 0) {
        if ((var.left_i > 0 && var.up_i > 0) && var.left_up_i > 0)
            check_around_if(tab_int, var);
    }
}

int **xxx_addition(int **tab_int, int *nb_rows, int *nb_cols)
{
    token_t var;

    for (var.i = 1; var.i < *nb_rows; var.i++) {
        for (var.j = 1; var.j < *nb_cols; var.j++) {
            var.left_i = tab_int[var.i][var.j - 1];
            var.up_i = tab_int[var.i - 1][var.j];
            var.left_up_i = tab_int[var.i - 1][var.j - 1];
            check_around(tab_int, var);
        }
    }
    return (tab_int);
}
