// htab_resize.c
// Řešení IJC-DU2, příklad b), 12.04.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"

void htab_resize(htab_t *t, size_t newn){
    htab_t *new_table = htab_init(newn);

    for(size_t i = 0; i < t->arr_size; i++){
        htab_item_t *tmp = t->arr_ptr[i];
        while(tmp != NULL){
            htab_pair_t *moved = htab_lookup_add(new_table, tmp->item.key);
            moved->value = tmp->item.value;

            tmp = tmp->next;
        }
    }

    htab_free(t);
    *t = *new_table;
}