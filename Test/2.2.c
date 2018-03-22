
#include <stdio.h>

int isPowerOfTwo(int number) {
    if (number < 0)
        number = -number;
    if (number == 0)
        return 0;
    while (number > 1) {
        if (number % 2 == 1) 
            return 0;
        number /= 2;
    }
    return 1;
}

int main() {
    int number;
    scanf("%d", &number);
    printf(isPowerOfTwo(number) ? "True" : "False");
    return 0;
}