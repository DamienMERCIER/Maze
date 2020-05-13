/*
** EPITECH PROJECT, 2020
** check_and_stock_n
** File description:
** check_and_stock_n
*/
#include "generator.h"

void stack_neighbor_valid_y(char **array, perfect_maze *perfect_maze)
{
    perfect_maze->i = 0;
    perfect_maze->stack = malloc(sizeof(char) * 4 + 1);
    if (perfect_maze->y_curent_cells < perfect_maze->col - 2 &&
    array[perfect_maze->y_curent_cells + 2][perfect_maze->x_curent_cells]
    == '*'){
        perfect_maze->stack[perfect_maze->i] = 'b';
        perfect_maze->x_neighbor_cell = perfect_maze->x_curent_cells;
        perfect_maze->y_neighbor_cell = perfect_maze->y_curent_cells + 2;
        perfect_maze->i++;
    }
    if (perfect_maze->y_curent_cells - 2 > 0 &&
    array[perfect_maze->y_curent_cells - 2][perfect_maze->x_curent_cells]
    == '*'){
        perfect_maze->stack[perfect_maze->i] = 't';
        perfect_maze->x_neighbor_cell = perfect_maze->x_curent_cells;
        perfect_maze->y_neighbor_cell = perfect_maze->y_curent_cells - 2;
        perfect_maze->i++;
    }
}

char *stack_neighbor_valid_x(char **array, perfect_maze *perfect_maze)
{

    if (perfect_maze->x_curent_cells < perfect_maze->row - 2 &&
    array[perfect_maze->y_curent_cells][perfect_maze->x_curent_cells + 2]
    == '*'){
        perfect_maze->stack[perfect_maze->i] = 'r';
        perfect_maze->x_neighbor_cell = perfect_maze->x_curent_cells + 2;
        perfect_maze->y_neighbor_cell = perfect_maze->y_curent_cells;
        perfect_maze->i++;
    }
    if (perfect_maze->x_curent_cells - 2 > 0 &&
    array[perfect_maze->y_curent_cells][perfect_maze->x_curent_cells - 2]
    == '*'){
        perfect_maze->stack[perfect_maze->i] = 'l';
        perfect_maze->x_neighbor_cell = perfect_maze->x_curent_cells - 2;
        perfect_maze->y_neighbor_cell = perfect_maze->y_curent_cells;
        perfect_maze->i++;
    }
    if (perfect_maze->i == 0)
        perfect_maze->stack = "abcd";
    return (perfect_maze->stack);
}