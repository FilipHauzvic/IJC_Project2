// htab_erase.c
// Řešení IJC-DU2, příklad b), 12.04.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"

//TODO Add resizing
bool htab_erase(htab_t * t, htab_key_t key){
    for(size_t i = 0; i < t->arr_size; i++){
        htab_item_t *prev = t->arr_ptr[i];
        htab_item_t *tmp = t->arr_ptr[i];
    
        while(tmp != NULL){
            if(strcmp(tmp->item.key, key) == 0){
                if(tmp == t->arr_ptr[i]){
                    t->arr_ptr[i] = tmp->next;
                }else{
                    prev->next = tmp->next;
                }
                free((void *)tmp->item.key);
                free(tmp);
                t->size--;
                
                // if(((double)t->size/t->arr_size) < AVG_LEN_MIN){
                //     htab_resize(t, t->arr_size * 2);
                // }
                return true;
            }else{
                prev = tmp;
                tmp = tmp->next;
            }
        }
    }
    return false;
}