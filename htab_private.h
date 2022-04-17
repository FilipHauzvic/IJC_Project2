// htab_private.h
// Řešení IJC-DU2, příklad b), 12.04.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#ifndef HTAB_PRIVATE_H
#define HTAB_PRIVATE_H 1

#include "htab.h"

#define AVG_LEN_MIN 5
#define AVG_LEN_MAX 15

typedef struct htab_item htab_item_t;
struct htab_item{
    htab_pair_t item;
    htab_item_t *next;
};

struct htab{
    size_t size; // number of items in htab
    size_t arr_size; // size of array
    htab_item_t *arr_ptr[]; // pointer to dynamic array of items (actual table)
};

#endif