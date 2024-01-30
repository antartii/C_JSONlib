/*
** EPITECH PROJECT, 2024
** anta-website
** File description:
** my_strlen
*/

#include "../includes/JSON_lib.h"

int my_strlen(const char *str)
{
    int count = 0;

    if (str == NULL)
        return -1;
    for (int i = 0; str[i] != '\0'; i += 1)
        count += 1;
    return count;
}
