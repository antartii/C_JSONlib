/*
** EPITECH PROJECT, 2024
** CSJON
** File description:
** JSON_clean
*/

#include "../../../includes/CJSON.h"

char *JSON_clean(char *JSON_string)
{
    int layer = 1;
    int reading_str = 0;
    char *result = NULL;
    int result_index = 0;
    int line_index = 0;
    int len_result = 0;

    //count char

    for (int i = 0; JSON_string[i] != '\0'; i += 1) {
        if (line_index == 0) {
            for (int i = 0; i < layer - 1; i += 1) {
                len_result += 1;
                line_index += 1;
            }
        }
        if (JSON_string[i] == '"') {
            if (reading_str == 0)
                reading_str = 1;
            else
                reading_str = 0;
        }
        if (JSON_string[i] != '\n' && JSON_string[i] != ' ' && JSON_string[i] != '\t' && reading_str == 0) {
            len_result += 1;
            line_index += 1;
            if (JSON_string[i] == '{' || JSON_string[i] == '[') {
                layer += 1;
                line_index = 0;
                len_result += 1;
            } else if (JSON_string[i] == '}' || JSON_string[i] == ']') {
                layer -= 1;
                line_index = 0;
                len_result += 1;
                len_result += 1;
            } else if (JSON_string[i] == ',') {
                line_index = 0;
                len_result += 1;
            }       
        } else if (reading_str == 1)
            len_result += 1;
    }
    len_result += 1;
    //code 

    layer = 1;
    reading_str = 0;
    result = malloc(sizeof(char) * len_result);
    result_index = 0;
    line_index = 0;

    for (int i = 0; JSON_string[i] != '\0'; i += 1) {
        if (line_index == 0) {
            for (int i = 0; i < layer - 1; i += 1) {
                result[result_index ++] = '\t';
                line_index += 1;
            }
        }
        if (JSON_string[i] == '"') {
            if (reading_str == 0)
                reading_str = 1;
            else
                reading_str = 0;
        }
        if (JSON_string[i] != '\n' && JSON_string[i] != ' ' && JSON_string[i] != '\t' && reading_str == 0) {
            result[result_index ++] = JSON_string[i];
            line_index += 1;
            if (reading_str == 0) {
                if (JSON_string[i] == '{' || JSON_string[i] == '[') {
                    layer += 1;
                    line_index = 0;
                    result[result_index++] = '\n';
                } else if (JSON_string[i] == '}' || JSON_string[i] == ']') {
                    layer -= 1;
                    result[result_index - 1] = '\n';
                    for (int i = 0; i < layer - 1; i += 1) {
                        result[result_index ++] = '\t';
                    }
                    result[result_index ++] = JSON_string[i];
                } else if (JSON_string[i] == ',') {
                    line_index = 0;
                    result[result_index++] = '\n';
                }
            }
        } else if (reading_str == 1)
            result[result_index++] = JSON_string[i];
    }
    result[result_index ++] = '\0';
    return result;
}
