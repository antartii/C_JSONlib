/*
** EPITECH PROJECT, 2024
** anta-website
** File description:
** my_realloc_str
*/

#include "../includes/CJSON.h"

int my_realloc_str(char **str, int reallocated_memory)
{
    char *old_str = (*str);

    if (str == NULL)
        return -1;
    if (reallocated_memory == 0) {
        free((*str));
        (*str) = NULL;
        return 0;
    }
    (*str) = malloc(sizeof(char) * reallocated_memory);
    for (int i = 0; i < my_strlen(old_str) && i < reallocated_memory; i += 1)
        (*str)[i] = old_str[i];
    free(old_str);
    return 0;
}
