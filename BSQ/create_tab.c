/*
** EPITECH PROJECT, 2018
** create_int_tab
** File description:
** BSQ
*/

struct var_replace
{
    int i;
    int u;
};

typedef struct var_replace var_replace_t;

void replace_nb(int **tab_int, char *buffer, int buffer_i, var_replace_t v)
{
    if (buffer[buffer_i] == '.')
        tab_int[v.i][v.u] = 1;
    if (buffer[buffer_i] == 'o')
        tab_int[v.i][v.u] = 0;
    if (buffer[buffer_i] != 'o' && buffer[buffer_i] != '.')
        exit(84);
}

int **buffer_to_int(char *buffer, int size, int *nb_rows, int *nb_cols)
{
    int **tab_int;
    int buffer_i = my_strlen(buffer) + 1;
    var_replace_t v;

    *nb_rows = get_nb_rows(buffer);
    *nb_cols = (size - buffer_i - 1) / *nb_rows;
    tab_int = malloc(sizeof(int *) * (*nb_rows));
    for (v.i = 0; v.i < *nb_rows; v.i++) {
        tab_int[v.i] = malloc(sizeof(int) * (*nb_cols));
        for (v.u = 0; v.u < *nb_cols; v.u++) {
            replace_nb(tab_int, buffer, buffer_i, v);
            buffer_i++;
        }
        buffer_i++;
    }
    return (tab_int);
}
