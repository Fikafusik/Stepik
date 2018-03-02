
#include <stdio.h>

int count(unsigned long long int n) {
    int ones = 0;
    while (n) {
        if (n & 1)
            ones++;
        n >>= 1;
    }
    return ones;
}

unsigned long long int n;

int main() {
    scanf("%llu", &n);
    printf("%d", count(n));
    return 0;
}