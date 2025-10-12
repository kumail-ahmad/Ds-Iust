
#include <stdio.h>

int power(int x, int y) {
    int result = 1;
    for(int i = 1; i <= y; i++) result *= x;
    return result;
}

int main() {
    int base, exponent;
    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exponent);
    printf("%d^%d = %d\n", base, exponent, power(base, exponent));
    return 0;
}
