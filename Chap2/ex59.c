#include<stdio.h>

int is_little_endian() {
        int x=1;
            return !((unsigned char*)&x)[0] == 0;
}

int exchange(int a, int b) {
    int c = b;
    unsigned char *cp = (unsigned char*) &c;
    unsigned char *ap = (unsigned char*) &a;
    if (is_little_endian()) {
        cp[0] = ap[0];
    }
    else {
        cp[sizeof(int)-1] = ap[sizeof(int)-1];
    }
    return c;
}

int main(int argc, char*argv[]) {
    int a = 0x89ABCDEF;
    int b = 0x76543210;
    int c = 0x765432EF;
    int c_out = exchange(a, b);
    if (c == c_out) {
        printf("Congratulations\n");
    }
    else {
        printf("Something wrong\n");
    }
}
