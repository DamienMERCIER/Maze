/*
** EPITECH PROJECT, 2020
** generator.h
** File description:
** generator.h
*/

#ifndef generator
#define generator

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct perfect_maze
{
    char **tab;
    char *stock;
    int *stack;
    char top_neighbor;
    char right_neighbor;
    char bottom_neighbor;
    char left_neighbor;
    int x_curent_cells;
    int y_curent_cells;
    int x_neighbor_cell;
    int y_neighbor_cell;
    int row;
    int col;
    int block;
    int i;
    int j;
    int k;
    char *real_stack;
    int len_of_stack;
    int total_of_cells;
    int nb_visited_cell;
    int h;
    int y;
    int max;
    int stop;
    int total_visited_cells;
}perfect_maze;

typedef struct s_global
{
    int ac;
    char **av;
}s_global;

/*
-- TOOLS FUNCTIONS --
*/
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);

/*
-- GENERATOR --
*/
void print_maze_color(char **maze, int width, int height);

/*
-- PERFECT_MAZE --
*/
char **create_starting_map(s_global *s_global, perfect_maze *perfect_maze);
char **search_visited_cells(s_global *s_global, perfect_maze *perfect_maze);
/*
-- CHECK_AND_STOCK_N --
*/
void check_neighbor(char **array, perfect_maze *perfect_maze);
char *stack_neighbor_valid_x(char **array, perfect_maze *perfect_maze);
/*
-- MAP --
*/
void my_init(perfect_maze *perfect_maze, s_global *s_global);
char **create_starting_map(s_global *s_global, perfect_maze *perfect_maze);
char **search_visited_cells(s_global *s_global, perfect_maze *perfect_maze);
/*
-- STACK --
*/
void create_and_fill_stack(perfect_maze *perfect_maze);

#endif /* !generator */

char choose_a_cell(perfect_maze *perfect_maze);
