
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define delimeters "."
#define textSize 1000

int compare(const void * str1, const void * str2) {
    char * _str1 = *(char **)str1;
    char * _str2 = *(char **)str2;
    int uppers1 = 0;
    int uppers2 = 0;
    int i;
    for (i = 0; i < strlen(_str1); ++i) 
        uppers1 += isupper(_str1[i]);
    for (i = 0; i < strlen(_str2); ++i)
        uppers2 += isupper(_str2[i]);
    return (uppers1 - uppers2);
}

char text[textSize];

int main() {
    fgets(text, textSize, stdin);
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
    qsort(sentenses, sentensesCount, sizeof(char *), compare);
    int i;
    for (i = 1; i < sentensesCount; ++i) {
        while(isspace((char)*sentenses[i])) 
            ++sentenses[i];
        printf("%s. ", sentenses[i]);
    }
    return 0; 
}