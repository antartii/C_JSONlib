/*
** EPITECH PROJECT, 2024
** anta-website
** File description:
** my_strcmp
*/

#include "../includes/JSON_lib.h"

int my_strcmp(const char *str, const char *str2)
{
    int str1_len = my_strlen(str);
    int str2_len = my_strlen(str2);

    if (str1_len != str2_len)
        return str1_len - str2_len;
    for (int i = 0; str[i] != '\0' && str2[i] != '\0'; i += 1) {
        if (str[i] != str2[i])
            return str[i] - str2[i];
    }
    return 0;
}
