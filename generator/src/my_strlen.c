/*
** EPITECH PROJECT, 2019
** strl
** File description:
** strl
*/

#include"generator.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}