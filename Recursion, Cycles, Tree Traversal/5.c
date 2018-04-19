
#include <stdio.h>

int recSum(int count) {
    if (count == 0)
        return 0;
    int number;
    scanf("%d", &number);
    return number + recSum(count - 1);
}

int main() {
    printf("%d", recSum(100));
    return 0;
}