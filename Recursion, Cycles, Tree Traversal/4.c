
#include <stdio.h>
#include <string.h>

void recDecToBin(int n, char* result) {
    if (n == 0)
        return;
    recDecToBin(n >> 1, result);
    result[strlen(result)] = n & 1 ? '1' : '0';
}

int main(){
    int n;
    char result[30] = "";
    scanf("%d", &n);       
    recDecToBin(n, result);
    puts(result);
    return 0;           
}