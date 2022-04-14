// htab_clear.c
// Řešení IJC-DU2, příklad b), 12.04.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"

void htab_clear(htab_t * t){
    for(size_t i = 0; i < t->arr_size; i++){
        while(t->arr_ptr[i] != NULL){
            // Find last pointer and remove it
            htab_item_t *lastItem = t->arr_ptr[i];
            while(lastItem->next != NULL){
                lastItem = lastItem->next;
            }
            free(lastItem->item.key);
            free(lastItem);
        }
    }
    t->size = 0;
}