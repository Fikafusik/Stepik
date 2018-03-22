
#include <stdio.h>

int digitCount(int number) {
    int digits = 0;
    do {
        number /= 10;
        ++digits;
    } while (number);
    return digits;
}

int main() {
    int number;
    scanf("%d", &number);
    printf("%d", digitCount(number));
    return 0;
}