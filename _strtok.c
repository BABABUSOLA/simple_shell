#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_shell.h"


char* my_strtok(char* str, const char* delimiter) {
    static char* nextToken = NULL; // Maintains the state of the next token

    // If str is not NULL, update the next token to start from str
    if (str != NULL) {
        nextToken = str;
    }

    // If nextToken is NULL, return NULL to indicate end of tokens
    if (nextToken == NULL) {
        return NULL;
    }

    // Find the beginning of the next token
    char* tokenStart = nextToken;
    while (*nextToken != '\0' && strchr(delimiter, *nextToken) != NULL) {
        nextToken++;
    }

    // If nextToken points to the end of the string, there are no more tokens
    if (*nextToken == '\0') {
        nextToken = NULL;
        return NULL;
    }

    // Find the end of the token
    char* tokenEnd = nextToken + 1;
    while (*tokenEnd != '\0' && strchr(delimiter, *tokenEnd) == NULL) {
        tokenEnd++;
    }

    // Null-terminate the token
    *tokenEnd = '\0';
    nextToken = tokenEnd + 1;

    return tokenStart;
}
