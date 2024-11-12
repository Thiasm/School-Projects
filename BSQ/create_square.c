/*
** EPITECH PROJECT, 2018
** create_square
** File description:
** BSQ
*/

struct var_for_max
{
    int max_i;
    int max_j;
    int max;
};

typedef struct var_for_max var_max_t;

void replace_max(int **tab_int, int i, int j, var_max_t *v)
{
    if (tab_int[i][j] > v->max) {
        v->max = tab_int[i][j];
        v->max_i = i;
        v->max_j = j;
    }
}

void find_max(int **tab_int, int *nb_rows, int *nb_cols, var_max_t *v)
{
    int i;
    int j;

    v->max = 0;
    for (i = 0; i < *nb_rows; i++) {
        for (j = 0; j < *nb_cols; j++) {
            replace_max(tab_int, i, j, v);
        }
    }
}

void find_square(int **tab_int, int *nb_rows, int *nb_cols)
{
    int i;
    int j;
    var_max_t v;

    find_max(tab_int, nb_rows, nb_cols, &v);
    for (i = (v.max_i - (v.max - 1)); i <= v.max_i; i++) {
        for (j = (v.max_j - (v.max - 1)); j <= v.max_j; j++) {
            tab_int[i][j] = -1 * tab_int[i][j];
        }
    }
}
