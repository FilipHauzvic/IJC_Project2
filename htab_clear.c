// htab_clear.c
// Řešení IJC-DU2, příklad b), 12.04.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"

void htab_clear(htab_t * t){
    for(size_t i = 0; i < t->arr_size; i++){
        htab_item_t *tmp = t->arr_ptr[i];

        while(tmp != NULL){
            htab_item_t *next_item = tmp->next;

            // casting to avoid compile warnings
            free((char *)tmp->item.key);
            free(tmp);

            tmp = next_item;
        }

        t->arr_ptr[i] = NULL;
    }
    t->size = 0;
}