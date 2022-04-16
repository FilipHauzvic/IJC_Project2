// io.c
// Řešení IJC-DU2, příklad b), 16.04.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include <ctype.h>
#include "io.h"

int read_word(char *s, int max, FILE *f){
    int length = 0;
    int c;

    while((c = getc(f)) != EOF && !isspace(c)){
        if(length >= max - 1){
            fprintf(stderr, "WARNING: Word exceeded maximum length limit");
            break;
        }
        s[length++] = c;
    }
    s[length] = '\0';

    if(feof(f)){
        return EOF;
    }else{
        return length;
    }
}