
#include <stdio.h>

long long int sum(long long int a, long long int b) {
    return a + b;
}

long long int a;
long long int b;

int main() {
    scanf("%lld %lld", &a, &b);
    printf("%lld", sum(a, b));
    return 0;
}