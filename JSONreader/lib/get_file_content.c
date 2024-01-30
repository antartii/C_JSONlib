/*
** JSON lib, 2024
** get_file_content
** File description:
** char *get_file_content()
*/

#include "../includes/JSON_lib.h"

char *get_file_content(char *file_path)
{
    struct stat file_stat;
    int file = open(file_path, O_RDONLY);
    char *file_content = NULL;
    ssize_t bytesread;

    if (file_path == NULL || file == -1)
        return NULL;
    if (stat(file_path, &file_stat) == -1)
        return NULL;
    file_content = malloc(sizeof(char) * (file_stat.st_size + 1));
    bytesread = read(file, file_content, file_stat.st_size);
    if (bytesread == -1) {
        free(file_content);
        return NULL;
    }
    file_content[file_stat.st_size] = '\0';
    close(file);
    return file_content;
}
