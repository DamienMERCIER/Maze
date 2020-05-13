/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include "generator.h"

void my_init(perfect_maze *perfect_maze, s_global *s_global)
{
    perfect_maze->total_of_cells =
    (atoi(s_global->av[1]) / 2) * (atoi(s_global->av[2]) / 2);
    perfect_maze->x_curent_cells = 1;
    perfect_maze->y_curent_cells = 1;
    perfect_maze->tab = create_starting_map(s_global, perfect_maze);
    perfect_maze->stack = malloc(sizeof(int) * 400000000);
    perfect_maze->y = 0;
    perfect_maze->total_visited_cells = 0;

    if (atoi(s_global->av[1]) > 3 && atoi(s_global->av[2]) > 3)
        perfect_maze->stock = "rb";
    else if (atoi(s_global->av[1]) <= 3 && atoi(s_global->av[2]) > 3)
        perfect_maze->stock = "b";
    else if (atoi(s_global->av[1]) > 3 && atoi(s_global->av[2]) <= 3)
        perfect_maze->stock = "r";
    else
        perfect_maze->stock = NULL;
}

void create_start_and_end(perfect_maze *perfect_maze, s_global *s_global)
{
    perfect_maze->tab[0][0] = 'o';
    perfect_maze->tab[0][1] = 'o';
    if ((atoi(s_global->av[2]) % 2 != 0 && atoi(s_global->av[1]) % 2 == 0) ||
    (atoi(s_global->av[2]) % 2 == 0 && atoi(s_global->av[1]) % 2 != 0) ||
    (atoi(s_global->av[2]) % 2 != 0 && atoi(s_global->av[1]) % 2 != 0))
        perfect_maze->tab[atoi(s_global->av[2]) - 1]
        [atoi(s_global->av[1]) - 1] = '*';
        if (atoi(s_global->av[1]) % 2 != 0)
    perfect_maze->tab[atoi(s_global->av[2]) - 1]
    [atoi(s_global->av[1]) - 2] = '*';
}

char **create_starting_map(s_global *s_global, perfect_maze *perfect_maze)
{
    perfect_maze->row = atoi(s_global->av[2]);
    perfect_maze->col = atoi(s_global->av[1]);

    perfect_maze->tab = malloc(sizeof(int *) * (perfect_maze->row + 1));
    for (int i = 0; i < perfect_maze->row; i++)
        perfect_maze->tab[i] = malloc(sizeof(int) * (perfect_maze->col + 1));
    for (int i = 0; i < perfect_maze->row; i++) {
        for (int j = 0; j < perfect_maze->col; j++) {
            if (j % 2 == 0 || i % 2 == 0)
                perfect_maze->tab[i][j] = 'X';
            else
                perfect_maze->tab[i][j] =  '*';
        }
    }
    create_start_and_end(perfect_maze, s_global);
    return (perfect_maze->tab);
}