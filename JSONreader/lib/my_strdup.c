/*
** EPITECH PROJECT, 2024
** secured
** File description:
** my_strdup
*/

#include "../includes/JSON_lib.h"

char *my_strdup(const char *src)
{
    char *str = NULL;
    int u = 0;
    int i = 0;

    if (src == NULL)
        return NULL;
    i = my_strlen(src);
    str = malloc(sizeof(char) * (i + 1));
    for (; src[u] != '\0'; u += 1) {
        str[u] = src[u];
    }
    str[u] = '\0';
    return str;
}
