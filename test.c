#include <stdio.h>

int main(void) {
    int value = 3;        // Binary: 00000011
    int result = value << 1; // Left shift by 1: 00000110 (value becomes 6)
    printf("%d %d\n", value, result); // Output: 6
    return 0;
}