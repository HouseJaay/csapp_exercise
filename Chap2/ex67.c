#include<stdio.h>

int int_size_is_32() {
    int set_msb = 1 << 31;
    int beyond_msb = 2 << 31;
    return set_msb && (!beyond_msb);
}
