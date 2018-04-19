
#include <stdio.h>

double recPow(int a, int n) {
    if (n < 0)
        return 1 / recPow(a, -n);
    if (a == 0)
        return 0.0;
    if (n == 0)
        return 1.0;
    if (n == 1)
        return (double)a;
    double pow = recPow(a, n >> 1);
    double res = pow * pow;
    if (n & 1)
        res *= a;
    return res;
}

int a;
int n;

int main() {
    scanf("%d %d", &a, &n);
    printf("%lf", recPow(a, n));
    return 0;
}