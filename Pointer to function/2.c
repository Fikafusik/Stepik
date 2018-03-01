
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 20

int compare_char(const void * lv, const void * rv) {
    return (*(const char *)lv - *(const char *)rv);
}

int compare_int(const void * lv, const void * rv) {
    return (*(const int *)lv - *(const int *)rv);
}

int compare_double(const void * lv, const void * rv) {
    return ((*(const double *)rv < *(const double *)lv) -
            (*(const double *)lv < *(const double * )rv));
}

size_t universalMax(const void * base, size_t num, size_t size, int(*cmp)(const void *, const void *)) {
    const char * pbase = (const char *)base;
    size_t index = 0;
    int i;
    for (i = 0; i < num; ++i)
        if (cmp(pbase + index * size, pbase + i * size) < 0) 
            index = i;
    return index;
}

int main() {
    size_t size;
    scanf("%zd", &size);

    int (*compare)(const void *, const void *);
    void * array;
    char * format_string;
    switch (size) {
    case 1:
        array = malloc(N * sizeof(char));
        format_string = " %c";
        compare = compare_char;
        break;
    case 4:
        array = malloc(N * sizeof(int));
        format_string = " %d";
        compare = compare_int;
        break;
    case 8:
        array = malloc(N * sizeof(double));
        format_string = " %lf";
        compare = compare_double;
        break;
    }
    for (int i = 0; i < N; ++i)
        scanf(format_string, array + i * size);
    printf("%zd", universalMax(array, N, size, compare));
    return 0;
}

