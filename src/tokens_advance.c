//
// Created by Antoine on 04/11/2018.
//

#include "bistro.h"

list_t **tokens_advance(list_t **tokens) {
    *tokens = (*tokens)->next;
    return tokens;
}