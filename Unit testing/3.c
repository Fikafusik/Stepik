
#include <stdio.h>

double pow_(int a, int b) {
    if (a == 0)
        return 0.0;
    if (b == 0)
        return 1.0;
    if (b < 0)
        return 1.0 / pow_(a, -b);
    double res = 1.0;
    for (int i = 0; i < b; ++i)
        res *= a;
    return res;
}

int a;
int b;

int main() {
    scanf("%d %d", &a, &b);
    printf("%lf", pow_(a, b));
    return 0;
}