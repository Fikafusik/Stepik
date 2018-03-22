
#include <stdio.h>

int isPowerOfTwo(int number) {
    if (number < 0)
        return (isPowerOfTwo(-number));
    if (number == 0)
        return 0; 
    if (number == 1)
        return 1;
    if (number & 1)
        return 0;
    return isPowerOfTwo(number >> 1);
}

int main() {
    int number;
    scanf("%d", &number);
    printf(isPowerOfTwo(number) ? "True" : "False");
    return 0;
}