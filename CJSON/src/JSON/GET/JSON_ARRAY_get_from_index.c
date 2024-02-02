/*
** EPITECH PROJECT, 2024
** CSJON
** File description:
** JSON_ARRAY_get_from_index
*/

#include "../../../includes/CJSON.h"

char *JSON_ARRAY_get_from_index(char const *JSON_string, int index)
{
    int layer = 0;
    int reading_str = 0;
    int start_index = 0;
    int end_index = 0;
    int reading_value = 0;
    int index_list = 0;

    for (int i = 0; JSON_string[i] != '\0'; i += 1) {
        if (JSON_string[i] == '"') {
            if (reading_str == 0)
                reading_str = 1;
            else if (reading_str == 1)
                reading_str = 0;
        } else if (reading_str == 0) {
            if (layer == 1 && reading_value == 0) {
                reading_value = 1;
                start_index = i;
            }
            if (layer == 1 && reading_value == 1 && JSON_string[i] == ',') {
                if (index_list == index) {
                    end_index = i - 1;
                    return select_str(JSON_string, start_index, end_index);
                } else {
                    reading_value = 0;
                }
            }
            if (JSON_string[i] == '{' || JSON_string[i] == '[') {
                layer += 1;
            } else if (JSON_string[i] == '}' || JSON_string[i] == ']') {
                layer -= 1;
            }
        }
    }
    return "ok";
}