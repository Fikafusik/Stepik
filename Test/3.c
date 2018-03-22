
#include <stdio.h>

int mod(int number) {
    return (number % 10);
}

int sqr(int number) {
    return (number * number);
}

int abs(int number) {
    return (number < 0 ? -number : number);
}

void forEachElement(int * array, size_t N, int (*func)(int)) {
    int i;
    for (i = 0; i < N; ++i) 
        array[i] = func(array[i]);
}

#define N 5

int main() {
    int array[N];
    int i;
    for (i = 0; i < N; ++i)
        scanf("%d", &array[i]);
    int type;
    scanf("%d", &type);
    int (*func)(int);
    switch (type) {
    case 1:
        func = mod;
        break;
    case 2:
        func = sqr;
        break;
    case 3:
        func = abs;
        break;
    default:
        printf("Error");
        return 0;
    }
    forEachElement(array, N, func);
    for (i = 0; i < N; ++i)
        printf("%d ", array[i]);
    return 0;
}