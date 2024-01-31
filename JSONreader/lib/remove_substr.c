/*
** LIB_JSON, 2024
** remove_substr.c
** File description:
** Remove a part of an str.
*/

#include "../includes/JSON_lib.h"

static int errors_remove_substr(char **adress, int start_index, int end_index)
{
    int len_str = 0;

    if ((*adress) == NULL)
        return -101;
    len_str = my_strlen((*adress));
    if (len_str == 0)
        return -100;
    if (end_index > len_str - 1)
        return -102;
    if (start_index < 0)
        return -104;
    if (end_index < 0)
        return -105;
    if (start_index > end_index)
        return -103;
    return 0;
}

int remove_substr(char **str_adress, int start_index, int end_index)
{
    int len_str = 0;
    int new_len = 0;
    char *temp = NULL;
    int index = 0;
    int error = errors_remove_substr(str_adress, start_index, end_index);

    if (error != 0)
        return error;
    temp = my_strdup(*str_adress);
    len_str = my_strlen((*str_adress));
    new_len = len_str - (end_index - start_index);
    if (start_index == 0 && end_index == len_str - 1) {
        free((*str_adress));
        (*str_adress) = NULL;
        return 0;
    }
    free((*str_adress));
    (*str_adress) = NULL;
    (*str_adress) = malloc(sizeof(char) * new_len);
    for (int i = 0; temp[i] != '\0'; i += 1) {
        if (i < start_index || i > end_index) {
            (*str_adress)[index] = temp[i];
            index += 1;
        }
    }
    (*str_adress)[index] = '\0';
    free(temp);
    return 0;
}
