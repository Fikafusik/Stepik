
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define delimeters " "
#define textSize 500

int main() {
    char text[textSize];
    fgets(text, textSize, stdin);
    if (text[strlen(text) - 1] == '\n')
        text[strlen(text) - 1] = '\0';
    size_t  sentensesCount = 0;
    size_t  sentensesSize = 1;
    char ** sentenses = (char **)malloc(sentensesSize * sizeof(char *));
    if (!sentenses)
        perror("malloc failed\n");
    char *  token = strtok(text, delimeters);
    while (token) {
        sentensesCount++;
        if (sentensesCount > sentensesSize) {
            sentensesSize <<= 1;
            sentenses = (char **)realloc(sentenses, sentensesSize * sizeof(char *));
            if (!sentenses)
                perror("realloc failed\n");
        }
        sentenses[sentensesCount - 1] = token;
        token = strtok(NULL, delimeters);
    }
    int i;
    int j;
    int itWas;
    int wordsCount;
    for (i = 0; i < sentensesCount; ++i) {
        itWas = 0;
        wordsCount = 0;
        for (j = 0; j < i; ++j)
            if (strcmp(sentenses[i], sentenses[j]) == 0)
                itWas = 1;
        for (j = i; j < sentensesCount; ++j)
            if (strcmp(sentenses[i], sentenses[j]) == 0)
                ++wordsCount;
        if (!itWas) 
            printf("%s %d\n", sentenses[i], wordsCount);
    }
    return 0;
}