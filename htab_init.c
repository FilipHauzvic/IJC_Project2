// htab_init.c
// Řešení IJC-DU2, příklad b), 12.04.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"

htab_t *htab_init(size_t n){
    htab_t *result = malloc(sizeof(htab_t) + n * sizeof(htab_item_t*));
    if(result == NULL){
        return NULL;
    }
    // Initialize table
    for(size_t i = 0; i < n; i++){
        result->arr_ptr[i] = NULL;
    }
    result->size = 0;
    result->arr_size = n;
    return result;
}