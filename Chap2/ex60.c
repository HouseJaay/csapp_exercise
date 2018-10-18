#include<stdio.h>
#include<limits.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    unsigned result = x;
    unsigned mask = UINT_MAX;
    unsigned bmask = b;
    int nshift = i << 3;
    mask = mask ^ (0xFF << nshift);
    result = result & mask;
    result = result | (bmask << nshift);
    return result;
}

int main(int argc, char *argv[]) {
    unsigned x = 0x12345678;
    if (replace_byte(x, 2, 0xAB) == 0x12AB5678) {
        printf("test1 pass\n");
    }
    else printf("test1 fail %x\n", replace_byte(x, 2, 0xAB));
    if (replace_byte(x, 0, 0xAB) == 0x123456AB) {
        printf("test2 pass\n");
    }
    else printf("test2 fail\n");
}
