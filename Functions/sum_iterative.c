
#include <stdio.h>

int sum(int n) {
    int total = 0;
    for(int i = 1; i <= n; i++) total += i;
    return total;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Sum of first %d natural numbers is %d\n", num, sum(num));
    return 0;
}
