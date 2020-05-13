/*
** EPITECH PROJECT, 2020
** perfect_maze
** File description:
** perfect_maze
*/

#include "generator.h"

char choose_a_cell(perfect_maze *perfect_maze)
{
    stack_neighbor_valid_x(perfect_maze->tab, perfect_maze);
    int len_of_stack = strlen(perfect_maze->stock);
    if (len_of_stack == 4)
        return ('e');
    int random = (rand() % len_of_stack);
    return (perfect_maze->stock[random]);
}

void detect_seleted_cell_r_b(char c, perfect_maze *perfect_maze)
{
    if (c == 'r') {
        perfect_maze->tab[perfect_maze->y_curent_cells]
        [perfect_maze->x_curent_cells + 2] = 'o';
        perfect_maze->tab[perfect_maze->y_curent_cells]
        [perfect_maze->x_curent_cells + 1] = 'o';
        perfect_maze->x_curent_cells = perfect_maze->x_curent_cells + 2;
    }
    if (c == 'b') {
        perfect_maze->tab[perfect_maze->y_curent_cells + 2]
        [perfect_maze->x_curent_cells] = 'o';
        perfect_maze->tab[perfect_maze->y_curent_cells + 1]
        [perfect_maze->x_curent_cells] = 'o';
        perfect_maze->y_curent_cells = perfect_maze->y_curent_cells + 2;
    }
}

void detect_seleted_cell(char c, perfect_maze *perfect_maze)
{
    detect_seleted_cell_r_b(c, perfect_maze);
    if (c == 't') {
        perfect_maze->tab[perfect_maze->y_curent_cells - 2]
        [perfect_maze->x_curent_cells] = 'o';
        perfect_maze->tab[perfect_maze->y_curent_cells - 1]
        [perfect_maze->x_curent_cells] = 'o';
        perfect_maze->y_curent_cells = perfect_maze->y_curent_cells - 2;
    }
    if (c == 'l') {
        perfect_maze->tab[perfect_maze->y_curent_cells]
        [perfect_maze->x_curent_cells -  2] = 'o';
        perfect_maze->tab[perfect_maze->y_curent_cells]
        [perfect_maze->x_curent_cells -  1] = 'o';
        perfect_maze->x_curent_cells = perfect_maze->x_curent_cells -  2;
    }
    perfect_maze->h++;
}

void blocked(perfect_maze *perfect_maze, char c)
{
    if (c == 'e' && perfect_maze->y > 0){
        perfect_maze->y_curent_cells =
        perfect_maze->stack[perfect_maze->y - 1];
        perfect_maze->x_curent_cells =
        perfect_maze->stack[perfect_maze->y -2];
        perfect_maze->stack[perfect_maze->y - 1] = 0;
        perfect_maze->stack[perfect_maze->y -2] = 0;
        perfect_maze->y -= 2;
    }
    if (perfect_maze->y <= 1){
        perfect_maze->y = perfect_maze->len_of_stack;
    }
}

char **search_visited_cells(s_global *s_global, perfect_maze *perfect_maze)
{
    my_init(perfect_maze, s_global);
    int h = 0;
    time_t t;
    char c = '\0';
    srand((unsigned) time(&t));
    perfect_maze->nb_visited_cell = h;
    int count = 0;
    int max = (atoi(s_global->av[1]) * 20) + (atoi(s_global->av[2]) * 20);
    int stop = perfect_maze->total_of_cells - 1;
    while (perfect_maze->total_visited_cells != stop) {
        perfect_maze->tab[perfect_maze->y_curent_cells]
        [perfect_maze->x_curent_cells] = 'c';
        c = choose_a_cell(perfect_maze);
        create_and_fill_stack(perfect_maze);
        detect_seleted_cell(c, perfect_maze);
        perfect_maze->tab[perfect_maze->y_curent_cells]
        [perfect_maze->x_curent_cells] = 'c';
        blocked(perfect_maze, c);
    }
    return (perfect_maze->tab);
}