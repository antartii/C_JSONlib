/*
** EPITECH PROJECT, 2024
** anta-website
** File description:
** insert_in_str
*/

#include "../includes/CJSON.h"

int insert_in_str(char **src, char *insert, int start_index)
{
    int insert_len = 0;
    int src_len = 0;

    if (src == NULL || insert == NULL)
        return -1;
    insert_len = my_strlen(insert);
    src_len = my_strlen((*src));
    if (start_index > src_len)
        return -1;
    my_realloc_str(src, src_len + insert_len + 1);
    for (int i = src_len; i >= start_index; i -= 1)
        (*src)[i + insert_len] = (*src)[i];
    for (int i = 0; insert[i] != '\0'; i += 1)
        (*src)[i + start_index] = insert[i];
    (*src)[src_len + insert_len] = '\0';
    return 0;
}
