#include<stdio.h>

int is_little_endian() {
    int x=1;
    return !((unsigned char*)&x)[0] == 0;
}

void main() {
    printf("%d\n", is_little_endian());
}
