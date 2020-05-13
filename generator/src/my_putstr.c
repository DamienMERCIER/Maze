/*
** EPITECH PROJECT, 2020
** putsrtr
** File description:
** putstr
*/
#include "generator.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}