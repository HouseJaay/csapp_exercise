#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    int w = 8 * sizeof(unsigned);
    unsigned mask = ~(UINT_MAX << (w-k));
    return xsra & mask;
}

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    int w = 8 * sizeof(int);
    int mask = -1 << (w-k);
    return xsrl ^ mask;
}

int main(int argc, char *argv[]) {
    int val = 0xffffffff;
    if (argc > 1) {
        val = strtol(argv[0], NULL, 0);
    }
    printf("origin %x\nsrl %x\nsra %x\n", val, srl(val,4), sra(val,4));
    return 0;
}

