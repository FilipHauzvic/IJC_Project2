// wordcount.c
// Řešení IJC-DU2, příklad b), 16.04.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "io.h"

#define MAX_WORD_LENGTH 128
#define HTAB_INIT_SIZE 255 // random for now, test speed of other values later

void print_pair(htab_pair_t *pair){
    printf("%s\t%i\n", pair->key, pair->value);
}

int main(){
    htab_t *table = htab_init(HTAB_INIT_SIZE);
    if(table == NULL){
        fprintf(stderr, "Error allocating memory for table\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH] = {0};
    int l;
    FILE *f = stdin;

    while((l = read_word(word, MAX_WORD_LENGTH, f)) != EOF){
        // skip whitespace characters between words
        if(word[0] == '\0'){
            continue;
        }
        htab_pair_t *added = htab_lookup_add(table, word);
        if(added == NULL){
            fprintf(stderr, "Error adding word into table\n");
            htab_free(table);
            return 1;
        }
    }

    htab_for_each(table, print_pair);
    htab_free(table);

    return 0;
}