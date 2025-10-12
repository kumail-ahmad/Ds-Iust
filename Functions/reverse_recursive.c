
#include <stdio.h>

void reverseNumber(int n) {
    if (n == 0) return;
    printf("%d", n % 10);
    reverseNumber(n / 10);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Reversed number: ");
    reverseNumber(num);
    printf("\n");
    return 0;
}
