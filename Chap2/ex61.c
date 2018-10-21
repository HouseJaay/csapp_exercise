#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

unsigned char get_msb(int x) {
    int nshift = (sizeof(int)-1) <<  3;
    return x >> nshift;
}

unsigned char get_lsb(int x) {
    int nshift = (sizeof(int)-1) <<  3;
    return (x << nshift) >> nshift;
}

int has_bit_1(int x) {
    return !!x;
}

int has_bit_0(int x) {
    return !x;
}

int has_bit_1_lsb(int x) {
    return !!get_lsb(x);
}

int has_bit_0_msb(int x) {
    return !get_msb(x);
}

int main(int argc, char *argv[]) {
    int val = 12345;
    if (argc > 1) {
        val = strtol(argv[1], NULL, 0);
    }
    printf("msb:%.2x\nlsb:%.2x\n",get_msb(val),get_lsb(val));
    if (has_bit_1(val)) printf("has bit 1\n");
    if (has_bit_0(val)) printf("has bit 0\n");
    if (has_bit_1_lsb(val)) printf("has bit 1 in lsb\n");
    if (has_bit_0_msb(val)) printf("has bit 0 in msb\n");
}
