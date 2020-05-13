/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generator
*/

#include "generator.h"

void print_maze_color(char **maze, int width, int height)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (maze[y][x] == '*')
                printf("\e[40m  \e[0m");
            else if (maze[y][x] == 'o')
                printf("\e[41m  \e[0m");
            else if (maze[y][x] == 'c')
                printf("\e[41m  \e[0m");
            else
                printf("\e[43m  \e[0m");
        }
        printf("\n");
    }
}
