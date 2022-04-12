// tail.c
// Řešení IJC-DU2, příklad a), 12.04.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 4096
#define DEFAULT_LINE_COUNT 10

typedef struct
{
    char **lines;
    size_t size;
    bool error;
} buffer_t;

void errorMsg(const char *message){
    fprintf(stderr, "%s\n", message);
}

// If parsing fails prints error message and retuns non-zero value
// Otherwise returns 0
int parseArgs(int argc, char *argv[], FILE **inputFile, int *lineCount){
    if(argc > 4){
        errorMsg("Too many arguments");
    }

    if(argc > 1){
        if((strcmp(argv[1], "-n") == 0)){
            if(argc > 2){
                *lineCount = strtol(argv[2], NULL, 10);

                if(argc > 3){
                    *inputFile = fopen(argv[3], "r");
                    if(!(*inputFile)){
                        errorMsg("Failed to open file");
                        return -1;
                    }
                }else{
                    *inputFile = stdin;
                }
            }else{
                errorMsg("Missing number of lines");
                return -1;
            }
        }else if(argc == 2){
            *lineCount = DEFAULT_LINE_COUNT;

            *inputFile = fopen(argv[1], "r");
            if(!(*inputFile)){
                errorMsg("Failed to open file");
                return -1;
            }
        }else{
            errorMsg("Invalid arguments");
            return -1;
        }
    }else{
        *lineCount = DEFAULT_LINE_COUNT;
        *inputFile = stdin;
    }
    return 0;
}

void bufferFree(buffer_t *buffer, size_t size){
    for(size_t i = 0; i < size; i++){
        free(buffer->lines[i]);
    }
    free(buffer->lines);
}

buffer_t bufferAlloc(size_t size){
    buffer_t buffer = {.error = false, .size = size};
    buffer.lines = malloc(sizeof(char *) * size);
    if(!buffer.lines){
        errorMsg("Error when allocating memory");
        buffer.error = true;
        return buffer;
    }
    for(size_t i = 0; i < size; i++){
        buffer.lines[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
        if(!buffer.lines[i]){
            errorMsg("Error when allocating memory");
            bufferFree(&buffer, i);
            buffer.error = true;
            return buffer;
        }
    }
    return buffer;
}

void bufferPrint(const buffer_t *buffer, size_t startingPos){
    size_t tmp = startingPos;
    for(size_t i = startingPos; i < (startingPos + buffer->size); i++){
        tmp = (i >= buffer->size) ? i % buffer->size : i;
        printf("%s", buffer->lines[tmp]);
    }
}

int main(int argc, char *argv[]){
    FILE *inputFile;
    int lineCount = 0;
    if(parseArgs(argc, argv, &inputFile, &lineCount) != 0){
        return 1;
    }

    buffer_t buffer = bufferAlloc(lineCount);
    size_t bufferIdx = 0;
    bool overflown = false;
    unsigned currentLine = 1;

    while(fgets(buffer.lines[bufferIdx], MAX_LINE_LENGTH, inputFile)){
        if(strlen(buffer.lines[bufferIdx]) == MAX_LINE_LENGTH - 1){
            if(buffer.lines[bufferIdx][MAX_LINE_LENGTH - 2] != '\n'){
                if(!overflown){
                    fprintf(stderr, "Line %u: ", currentLine);
                    errorMsg("length limit exceeded!");
                    overflown = true;
                }
                int c;
                // need this to read rest of line, but we don't do anything with the remaining chars
                while((c = getc(inputFile)) != '\n' && c != EOF){
                    (void)42;
                }
                buffer.lines[bufferIdx][MAX_LINE_LENGTH - 2] = '\n';
            }
        }
        // printf("%lu %s\n", strlen(buffer.lines[bufferIdx]), buffer.lines[bufferIdx]);
        currentLine++;
        bufferIdx++;
        if(bufferIdx >= buffer.size){
            bufferIdx = 0;
        }
    }

    bufferPrint(&buffer, bufferIdx);
    bufferFree(&buffer, buffer.size);
    if(inputFile != stdin){
        free(inputFile);
    }

    return 0;
}