/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** main_function
*/

#include <sys/types.h>
#include <unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdlib.h>

char *create_buffer(char *filepath, int size)
{
    int fd;
    char *buffer;

    buffer = malloc(sizeof (char) * size);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        exit(84);
    read(fd, buffer, size);
    close(fd);
    if (buffer[0] == NULL)
        exit(84);
    return (buffer);
}

int main(int argc, char **argv)
{
    int size;
    char *buffer;
    char *final;
    int **tab_int;
    int nb_rows;
    int nb_cols;

    size = get_size(argv[1]);
    buffer = malloc(sizeof(char) * size);
    buffer = create_buffer(argv[1], size);
    tab_int = buffer_to_int(buffer, size, &nb_rows, &nb_cols);
    free(buffer);
    xxx_addition(tab_int, &nb_rows, &nb_cols);
    find_square(tab_int, &nb_rows, &nb_cols);
    final = malloc(sizeof(char) * (size));
    create_final(tab_int, &nb_rows, &nb_cols, final);
    write(1, final, my_strlen_tot(final));
    free(final);
    return (0);
}
