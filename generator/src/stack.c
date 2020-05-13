/*
** EPITECH PROJECT, 2020
** stack
** File description:
** stack
*/

#include "generator.h"

int my_put_nbr(int nb)
{
    long nb2;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            nb2 = (nb % 10);
            nb = (nb - nb2) / 10;
            my_put_nbr(nb);
            my_putchar(nb2 + 48);
        }
        else
            my_putchar(48 + nb % 10);
    }
    if (nb == -2147483648)
        my_putstr("2147483648");
    return (0);
}

void create_and_fill_stack(perfect_maze *perfect_maze)
{
    static int l = 0;
    perfect_maze->len_of_stack = l;
    int len = strlen(perfect_maze->stock);
    if (len > 1 && len < 4){
        perfect_maze->stack[l] = perfect_maze->x_curent_cells;
        perfect_maze->stack[l + 1] = perfect_maze->y_curent_cells;
        l = l + 2;
        perfect_maze->y += 2;
    }
    int i = 0;
    perfect_maze->max = 0;
    perfect_maze->stop = 0;
    while (i != perfect_maze->len_of_stack){
        i++;
        if (perfect_maze->stack[i] == 0)
            perfect_maze->max++;
    }
    if (perfect_maze->max != 0 && perfect_maze->max ==
    perfect_maze->len_of_stack)
        perfect_maze->stop = 1;
}