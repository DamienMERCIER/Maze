/*
** EPITECH PROJECT, 2020
** check_and_stock_n
** File description:
** check_and_stock_n
*/
#include "generator.h"

void check_neighbor(char **array, perfect_maze *perfect_maze)
{
    perfect_maze->right_neighbor = 'o';
    if (perfect_maze->x_curent_cells < perfect_maze->row - 2) {
        array[perfect_maze->y_curent_cells][perfect_maze->x_curent_cells + 2]
        = perfect_maze->right_neighbor;
    }
    perfect_maze->bottom_neighbor = 'o';
    if (perfect_maze->y_curent_cells < perfect_maze->col - 2) {
        array[perfect_maze->y_curent_cells + 2][perfect_maze->x_curent_cells]
        = perfect_maze->bottom_neighbor;
        perfect_maze->top_neighbor = 'o';
    }
    if (perfect_maze->y_curent_cells - 2 > 0) {
        array[perfect_maze->y_curent_cells - 2][perfect_maze->x_curent_cells]
        = perfect_maze->top_neighbor;
    }
    perfect_maze->left_neighbor = 'o';
    if (perfect_maze->y_curent_cells - 2 > 0) {
        array[perfect_maze->y_curent_cells][perfect_maze->x_curent_cells - 2]
        = perfect_maze->left_neighbor;
    }
}

void stack_neighbor_valid_y(char **array, perfect_maze *perfect_maze)
{
    perfect_maze->j = 0;
    perfect_maze->stock = malloc(sizeof(char) * 4 + 1);
    if (perfect_maze->y_curent_cells < perfect_maze->row - 2 &&
    array[perfect_maze->y_curent_cells + 2][perfect_maze->x_curent_cells]
    == '*'){
        perfect_maze->stock[perfect_maze->j] = 'b';
        perfect_maze->x_neighbor_cell = perfect_maze->x_curent_cells;
        perfect_maze->y_neighbor_cell = perfect_maze->y_curent_cells + 2;
        perfect_maze->j++;
    }
    if (perfect_maze->y_curent_cells - 2 > 0 &&
    array[perfect_maze->y_curent_cells - 2][perfect_maze->x_curent_cells]
    == '*'){
        perfect_maze->stock[perfect_maze->j] = 't';
        perfect_maze->x_neighbor_cell = perfect_maze->x_curent_cells;
        perfect_maze->y_neighbor_cell = perfect_maze->y_curent_cells - 2;
        perfect_maze->j++;
    }
}

char *stack_neighbor_valid(char **array, perfect_maze *perfect_maze)
{
    if (perfect_maze->x_curent_cells < perfect_maze->col - 2 &&
    array[perfect_maze->y_curent_cells][perfect_maze->x_curent_cells + 2]
    == '*'){
        perfect_maze->stock[perfect_maze->j] = 'r';
        perfect_maze->x_neighbor_cell = perfect_maze->x_curent_cells + 2;
        perfect_maze->y_neighbor_cell = perfect_maze->y_curent_cells;
        perfect_maze->j++;
    }
}

char *stack_neighbor_valid_x(char **array, perfect_maze *perfect_maze)
{
    stack_neighbor_valid_y(array, perfect_maze);
    stack_neighbor_valid(array, perfect_maze);
    if (perfect_maze->x_curent_cells - 2 > 0 &&
    array[perfect_maze->y_curent_cells][perfect_maze->x_curent_cells - 2]
    == '*'){
        perfect_maze->stock[perfect_maze->j] = 'l';
        perfect_maze->x_neighbor_cell = perfect_maze->x_curent_cells - 2;
        perfect_maze->y_neighbor_cell = perfect_maze->y_curent_cells;
        perfect_maze->j++;
    }
    if (perfect_maze->j == 0)
        perfect_maze->stock = "abcd";
    if (perfect_maze->j != 0)
        perfect_maze->total_visited_cells += 1;
    return (perfect_maze->stock);
}