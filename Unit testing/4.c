
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count(char * str) {
    size_t  wordsCount = 0;
    size_t  wordsSize = 1;
    char ** words = (char **)malloc(wordsSize * sizeof(char *));
    
    char * token = strtok(str, " \n");
    while (token) {
        wordsCount++;
        if (wordsCount > wordsSize) {
            wordsSize <<= 1;
            words = (char **)realloc(words, wordsSize * sizeof(char *));
        }
        words[wordsCount - 1] = token;
        token = strtok(NULL, " ");
    }
    
    int i;
    int j;
    int curr_max;
    int maximum = 0;
    for (i = 0; i < wordsCount; ++i) {
        curr_max = 0;
        for (j = i; j < wordsCount; ++j)
            if (strcmp(words[i], words[j]) == 0)
                curr_max++;
        if (maximum < curr_max)
            maximum = curr_max;
    }
    if (wordsCount == 1 && strcmp(words[0], " ") == 0)
        return 0;
    return maximum;
}

#define textSize 200

char text[textSize];

int main() {
    fgets(text, textSize, stdin);
    if (text[strlen(text) - 1] == '\n')
        text[strlen(text) - 1] = '\0';
    printf("%d", count(text));
    return 0;
}