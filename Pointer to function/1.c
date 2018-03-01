
#include <stdio.h>

int func1(int);
int func2(int);
int func3(int);
void forEachElement(int *, int, int(*)(int));

#define N 500
int a[N], q;

int main() {
    int i;
    for (i = 0; i < N; ++i)
        scanf(" %d", &a[i]);
    scanf(" %d", &q);
    switch (q) {
        case 1:
            forEachElement(a, N, func1);
            break;
        case 2:
            forEachElement(a, N, func2);
            break;
        case 3:
            forEachElement(a, N, func3);
            break;
        default:
            printf("Error");
            return 0;
    }
    for (i = 0; i < N; ++i)
        printf("%d\n", a[i]);
    return 0;
}

int func1(int n) {
    return (n << 1);
}

int func2(int n) {
    return (n * n * n);
}

int func3(int n) {
    return (n < 0 ? -n : n);
}

void forEachElement(int * array, int n, int (* func)(int)) {
    int i;
    for (i = 0; i < n; ++i)
        array[i] = func(array[i]);
}