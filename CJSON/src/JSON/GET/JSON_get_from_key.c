/*
** EPITECH PROJECT, 2024
** anta-website
** File description:
** JSON_get_from_key
*/

#include "../../../includes/CJSON.h"

char *JSON_get_from_key(char *JSON, char *key)
{
    int layer = -1;
    int can_read_value = 0;
    int reading_JSONkey = 0;
    int reading_string = 0;
    int JSONkey_indexes[2];
    int value_indexes[2];
    char *JSONkey = NULL;

    if (JSON == NULL || key == NULL)
        return NULL;
    for (int i = 0; JSON[i] != '\0'; i += 1) {
        if (JSON[i] == '"') {
            if (layer == 0) {
                if (reading_JSONkey == 0) {
                    JSONkey_indexes[0] = i + 1;
                    reading_JSONkey = 1;
                } else if (reading_JSONkey == 1) {
                    JSONkey_indexes[1] = i - 1;
                    reading_JSONkey = 2;
                    JSONkey = select_str(JSON, JSONkey_indexes[0], JSONkey_indexes[1]);
                    if (my_strcmp(key, JSONkey) == 0)
                        can_read_value = 1;
                    free(JSONkey);
                }
            } else {
                if (reading_string == 0)
                    reading_string = 1;
                else if (reading_string == 1)
                    reading_string = 0;
            }
        }
        if (JSON[i] == ':' && reading_string == 0) {
            if (layer == 0 && can_read_value == 1)
                value_indexes[0] = i + 1;
        }
        if (reading_string == 0) {
            if (JSON[i] == ',' && layer == 0) {
                    if (can_read_value == 1) {
                        value_indexes[1] = i - 1;
                        return select_str(JSON, value_indexes[0], value_indexes[1]);
                    } else
                        reading_JSONkey = 0;
            }
            if (JSON[i] == '[' || JSON[i] == '{')
                layer += 1;
            else if (JSON[i] == ']')
                layer -= 1;
            else if (JSON[i] == '}') {
                if (layer == 0 && can_read_value == 1) {
                    value_indexes[1] = i - 1;
                    return select_str(JSON, value_indexes[0], value_indexes[1]);
                } else
                    layer -= 1;
            }
        }
    }
    return "test";
}
