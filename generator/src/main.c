/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/
#include "generator.h"

int main(int ac, char **av)
{
    s_global s_global;
    perfect_maze perfect_maze;
    s_global.ac = ac;
    s_global.av = av;
    if (ac == 3 || ac == 4)
        print_maze_color(search_visited_cells(&s_global, &perfect_maze),
        atoi(av[1]), atoi(av[2]));
        else {
            my_putstr("Wrong format\nUSAGE: ");
            my_putstr("./generator [size] [size] [perfect]\n");
            return (84);
        }
}
