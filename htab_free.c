// htab_free.c
// Řešení IJC-DU2, příklad b), 12.04.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include <stdlib.h>
#include "htab.h"

void htab_free(htab_t * t){
    htab_clear(t);
    free(t);
    return;
}