
#include <stdio.h>
#include <stdint.h>

int isByte(int value) {
    return (value >= 0 && value <= 255);
}

int main() {

    int ip1, ip2, ip3, ip4;
    scanf("%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4);
    if (!isByte(ip1) || !isByte(ip2) || !isByte(ip3) || !isByte(ip4)) {
        printf("wrong IP");
        return 0;
    }
    uint32_t ip = (ip1 << 24) + (ip2 << 16) + (ip3 << 8) + (ip4 << 0);

    int mask1, mask2, mask3, mask4;
    scanf("%d.%d.%d.%d", &mask1, &mask2, &mask3, &mask4);
    if (!isByte(mask1) || !isByte(mask2) || !isByte(mask3) || !isByte(mask4)) {
        printf("wrong MASK");
        return 0;
    }
    uint32_t mask = (mask1 << 24) + (mask2 << 16) + (mask3 << 8) + (mask4 << 0);

    uint32_t mask_ = ~mask;
    uint32_t one = 1;
    
    int n;
    for (n = 0; mask_ & one; n++) 
        one <<= 1;
    for (n = 32 - n; n > 0; --n) {
        one <<= 1;
        if (mask_ & one) {
            printf("wrong MASK");
            return 0;
        }
    }

    printf("%d.%d.%d.%d", ip1 & mask1, ip2 & mask2, ip3 & mask3, ip4 & mask4);
    return 0;
}