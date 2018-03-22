
#include <stdio.h>
#include <math.h>

int main() {
    long double number, intpart, fracpart;
    scanf("%Lf", &number);
    fracpart = modfl(number , &intpart);
    printf("%Lf\n%Lf", intpart, fracpart);
    return 0;
}