/*
** EPITECH PROJECT, 2024
** CSJON
** File description:
** JSON_create_data
*/

#include "../../../includes/CJSON.h"
#include <stdio.h>

data_t *JSON_init_data()
{
    data_t *JSON_DATA = malloc(sizeof(data_t));

    JSON_DATA->index = 0;
    JSON_DATA->key = NULL;
    JSON_DATA->value = NULL;
    JSON_DATA->prev = NULL;
    JSON_DATA->next = NULL;
    return JSON_DATA;
}

int JSON_add_value(data_t **JSON_DATA, char *key, char *value)
{
    if ((*JSON_DATA)->key == NULL) {
        (*JSON_DATA)->key = my_strdup(key);
        (*JSON_DATA)->value = my_strdup(value);
        (*JSON_DATA)->index = 0;
        (*JSON_DATA)->prev = NULL;
        (*JSON_DATA)->next = NULL;
    } else {
        while ((*JSON_DATA)->next != NULL)
            (*JSON_DATA) = (*JSON_DATA)->next;
        (*JSON_DATA)->next = JSON_init_data();
        (*JSON_DATA)->next->prev = (*JSON_DATA);
        (*JSON_DATA)->next->key = my_strdup(key);
        (*JSON_DATA)->next->value = my_strdup(value);
        (*JSON_DATA)->next->index = (*JSON_DATA)->index + 1;
        (*JSON_DATA) = (*JSON_DATA)->next;
    }
    return 0;
}

int JSON_delete_all_data(data_t **JSON_DATA)
{
    while ((*JSON_DATA)->prev != NULL)
        (*JSON_DATA) = (*JSON_DATA)->prev;
    while ((*JSON_DATA)->next != NULL) {
        free((*JSON_DATA)->key);
        free((*JSON_DATA)->value);
        (*JSON_DATA) = (*JSON_DATA)->next;
        free((*JSON_DATA)->prev);
        (*JSON_DATA)->prev = NULL;
    }
    free((*JSON_DATA)->key);
    free((*JSON_DATA)->value);
    if ((*JSON_DATA)->prev != NULL) {
        free((*JSON_DATA)->prev);
        (*JSON_DATA)->prev = NULL;
    }
    free((*JSON_DATA));
    (*JSON_DATA) = NULL;
    return 0;
}

int JSON_show_data(data_t *JSON_DATA)
{
    while (JSON_DATA->prev != NULL)
        JSON_DATA = JSON_DATA->prev;
    while (JSON_DATA->next != NULL) {
        printf("/////////////////////\n");
        printf("id : %d\n", JSON_DATA->index);
        printf("key : %s\n", JSON_DATA->key);
        printf("value : %s\n\n", JSON_DATA->value);
        JSON_DATA = JSON_DATA->next;
    }
    printf("/////////////////////\n");
    printf("id : %d\n", JSON_DATA->index);
    printf("key : %s\n", JSON_DATA->key);
    printf("value : %s\n\n", JSON_DATA->value);
    return 0;
}