/*
** lib JSON, 2024
** select_str
** File description:
** select_str
*/

#include "../includes/JSON_lib.h"

char *select_str(const char *str, int start, int end)
{
    int result_len = end + 1 - start;
    char *result = NULL;
    int len_str = 0;

    if (str == NULL || end < 0 || start < 0 || start > end)
        return NULL;
    len_str = my_strlen(str);
    if (end >= len_str)
        return NULL;
    result = malloc(sizeof(char) * (result_len + 1));
    for (int i = start; i < end + 1; i += 1)
        result[i - start] = str[i];
    result[result_len] = '\0';
    return result;
}
