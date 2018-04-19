
#include <stdio.h>

void rec(int magic) {
    if (magic == 0)
        return;
    int number;
    scanf("%d", &number);
    rec(magic - 1);
    printf("%d ", number);
}

int n;

int main() {
    scanf("%d", &n);
    rec(n);
    return 0;
}