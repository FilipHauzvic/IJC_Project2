// htab_lookup_add.c
// Řešení IJC-DU2, příklad b), 12.04.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key){
    size_t index = htab_hash_function(key) % t->arr_size;
    htab_pair_t *input_pair = htab_find(t, key);
    htab_item_t *tmp = t->arr_ptr[index];

    if(input_pair == NULL){
        // Create new item
        htab_item_t *new_item = malloc(sizeof(htab_item_t));
        if(new_item == NULL){
            return NULL;
        }

        new_item->item.key = malloc(sizeof(char) * (strlen(key) + 1));
        if(new_item->item.key == NULL){
            return NULL;
        }

        new_item->item.value = 1;
        strcpy((char *)new_item->item.key, key);
        new_item->next = NULL;

        if(tmp == NULL){
            t->arr_ptr[index] = new_item;
        }else{
            while (tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next = new_item;
        }

        t->size++;
        // new_item scope only in this branch of if-statement
        tmp = new_item;

        // if(((double)t->size/t->arr_size) > AVG_LEN_MAX){
        //     htab_resize(t, t->arr_size * 2);
        // }
    }else{
        input_pair->value++;
    }
    return &(tmp->item);
}