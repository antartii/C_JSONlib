/*
** lib JSON, 2024
** JSON_lib.h
** File description:
** lib of all functions from the JSON lib
*/

#ifndef JSON_LIB
    #define JSON_LIB
    #include <stddef.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdlib.h>

// base lib
int my_strlen(const char *str);
int my_strcmp(const char *str, const char *str2);
int remove_substr(char **str_adress, int start_index, int end_index);
char *get_file_content(char *file_path);
char *select_str(const char *str, int start, int end);
int insert_in_str(char **src, char *insert, int start_index);
int my_realloc_str(char **str, int reallocated_memory);
char *my_strdup(const char *src);

// JSON lib
char *JSON_get_from_key(char *JSON, char *key);
char *JSON_get_from_keys(char *JSON, int count, ...);

//

#endif /* !JSON_LIB */