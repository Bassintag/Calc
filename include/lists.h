//
// Created by Antoine on 04/11/2018.
//

#ifndef BISTRO_LISTS_H
#define BISTRO_LISTS_H

typedef struct list_s {
    struct list_s *next;
    void *value;
} list_t;

list_t *list_create(void *);
int list_append(list_t **, void *);

#endif //BISTRO_LISTS_H
