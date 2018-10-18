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

int main(int argc, char *argv[]) {
    int val = 12345;
    if (argc > 1) {
        val = strtol(argv[1], NULL, 0);
    }
    printf("msb:%x\nlsb:%x\n",get_msb(val),get_lsb(val));
}
