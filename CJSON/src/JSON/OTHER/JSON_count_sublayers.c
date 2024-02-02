/*
** EPITECH PROJECT, 2024
** CSJON
** File description:
** JSON_count_sublayers
*/

int JSON_count_sublayers(char const *JSON_string)
{
    int sublayers = 0;
    int layer = -1;
    int reading_str = 0;
    int reading_value = 0;

    for (int i = 0; JSON_string[i] != '\0'; i += 1) {
        if (JSON_string[i] == '"') {
            if (reading_str == 0)
                reading_str = 1;
            if (reading_str == 1)
                reading_str = 0;
        } else if (JSON_string[i] == '{' || JSON_string[i] == '[') {
            if (reading_str == 0 && reading_value == 0 && layer == 0) {
                reading_value = 1;
            }
            layer += 1;
        } else if (JSON_string[i] == '}' || JSON_string[i] == ']') {
            if (reading_str == 0 && reading_value == 1 && layer == 1) {
                sublayers += 1;
                reading_value = 0;
            }
            layer -= 1;
        }
    }
    return sublayers;
}
