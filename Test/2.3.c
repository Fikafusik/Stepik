
#include <stdio.h>
#include <stdlib.h>

int isPowerOfTwo(int number) {
    if (number == 0)
        return 0;
    number = abs(number);
    return !(number & (number - 1));
}

int main() {
    int number;
    scanf("%d", &number);
    printf(isPowerOfTwo(number) ? "True" : "False");
    return 0;
}