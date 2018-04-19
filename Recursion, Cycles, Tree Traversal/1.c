
#include <stdio.h>

long long int factorial(int number) {
    return (number ? number * (factorial(number - 1)) : 1);
}

int main() {
    int number;
    scanf("%d", &number);
    printf("%lld", factorial(number));
    return 0;
}