/*
** EPITECH PROJECT, 2024
** CSJON
** File description:
** JSON_get_all_subkeys
*/

#include "../../../includes/CJSON.h"

char **JSON_get_all_subkeys(char const *JSON_string)
{
    int layer = -1;
    int can_read_value = 0;
    int reading_JSONkey = 0;
    int reading_string = 0;
    int JSONkey_indexes[2];
    char **keys = NULL;
    int keys_index = 0;
    int keys_len = 0;

    if (JSON_string == NULL)
        return NULL;

    //count malloc 
    for (int i = 0; JSON_string[i] != '\0'; i += 1) {
        if (JSON_string[i] == '"') {
            if (layer == 0) {
                if (reading_JSONkey == 0) {
                    JSONkey_indexes[0] = i + 1;
                    reading_JSONkey = 1;
                } else if (reading_JSONkey == 1) {
                    JSONkey_indexes[1] = i - 1;
                    reading_JSONkey = 2;
                    keys_len += 1;
                }
            } else {
                if (reading_string == 0)
                    reading_string = 1;
                else if (reading_string == 1)
                    reading_string = 0;
            }
        }
        if (reading_string == 0) {
            if (JSON_string[i] == ',' && layer == 0) {
                    if (can_read_value == 1) {
                    } else
                        reading_JSONkey = 0;
            }
            if (JSON_string[i] == '[' || JSON_string[i] == '{')
                layer += 1;
            else if (JSON_string[i] == ']')
                layer -= 1;
            else if (JSON_string[i] == '}') {
                if (layer == 0 && can_read_value == 1) {
                } else
                    layer -= 1;
            }
        }
    }
    keys = malloc(sizeof(char *) * keys_len);
    //code 
    for (int i = 0; JSON_string[i] != '\0'; i += 1) {
        if (JSON_string[i] == '"') {
            if (layer == 0) {
                if (reading_JSONkey == 0) {
                    JSONkey_indexes[0] = i + 1;
                    reading_JSONkey = 1;
                } else if (reading_JSONkey == 1) {
                    JSONkey_indexes[1] = i - 1;
                    reading_JSONkey = 2;
                    keys[keys_index++] = select_str(JSON_string, JSONkey_indexes[0], JSONkey_indexes[1]);
                }
            } else {
                if (reading_string == 0)
                    reading_string = 1;
                else if (reading_string == 1)
                    reading_string = 0;
            }
        }
        if (reading_string == 0) {
            if (JSON_string[i] == ',' && layer == 0) {
                    if (can_read_value == 1) {
                    } else
                        reading_JSONkey = 0;
            }
            if (JSON_string[i] == '[' || JSON_string[i] == '{')
                layer += 1;
            else if (JSON_string[i] == ']')
                layer -= 1;
            else if (JSON_string[i] == '}') {
                if (layer == 0 && can_read_value == 1) {
                } else
                    layer -= 1;
            }
        }
    }
    return keys;
}