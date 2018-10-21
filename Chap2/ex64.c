#include<stdio.h>

int any_odd_one(unsigned x) {
    unsigned mask = 0b10101010101010101010101010101010;
    return !((mask & x) == x);
}

int main(void) {
    printf("%d\n", any_odd_one(0b10));
    printf("%d\n", any_odd_one(0b01));
    return 0;
}
