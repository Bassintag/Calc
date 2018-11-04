//
// Created by Antoine on 04/11/2018.
//

#include <stdlib.h>
#include "lists.h"

list_t *list_create(void *value) {
    list_t *ret = malloc(sizeof(list_t));

    if (!ret)
        return (NULL);
    ret->next = NULL;
    ret->value = value;
    return (ret);
}