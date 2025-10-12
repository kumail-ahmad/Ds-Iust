#include <stdio.h>
int main() {
    char s[100];
    printf("Enter a string: ");
    fgets(s, 100, stdin);
    int i = 0;
    while (s[i] && s[i] != '\n') i++;
    printf("Length = %d\n", i);
    return 0;
}
