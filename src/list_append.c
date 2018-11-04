//
// Created by Antoine on 04/11/2018.
//

#include "lists.h"

int list_append(list_t **list, void *value) {
    list_t *new = list_create(value);
    list_t *last = *list;

    if (!new)
        return (84);
    if (!last) {
        *list = new;
        return (0);
    }
    while (last->next)
        last = last->next;
    last->next = new;
    return (0);
}