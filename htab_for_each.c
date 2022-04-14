// htab_for_each.c
// Řešení IJC-DU2, příklad b), 12.04.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "htab_private.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    for(size_t i = 0; i < t->arr_size; i++){
        htab_item_t *tmp = t->arr_ptr[i];

        while(tmp != NULL){
            f(&(tmp->item));
            tmp = tmp->next;
        }
    }
}