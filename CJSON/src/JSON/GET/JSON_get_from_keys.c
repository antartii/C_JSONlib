/*
** EPITECH PROJECT, 2024
** anta-website
** File description:
** JSON_get_from_keys
*/

#include "../../../includes/CJSON.h"

char *JSON_get_from_keys(char *JSON, int count, ...)
{
    char *JSONvalue = JSON;
    char *temp = NULL;
    va_list keys;
    va_start(keys, count);

    for (int i = 0; i < count; i += 1) {
        JSONvalue = JSON_get_from_key(JSONvalue, va_arg(keys, char *));
        if (temp != NULL) {
            free(temp);
        }
        temp = JSONvalue;
    }
    return JSONvalue;
}