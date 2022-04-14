// htab_find.c
// Řešení IJC-DU2, příklad b), 12.04.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "htab_private.h"

htab_pair_t * htab_find(htab_t * t, htab_key_t key){
    for(size_t i = 0; i < t->arr_size; i++){
        htab_item_t *tmp = t->arr_ptr[i];
    
        while(tmp != NULL){
            if(strcmp(tmp->item.key, key) == 0){
                return &(tmp->item);
            }
        }
    }
    return NULL;
}