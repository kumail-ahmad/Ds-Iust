#include <stdio.h>
int main() {
    char s1[100], s2[100];
    printf("Enter a string: ");
    fgets(s1, 100, stdin);
    int i = 0;
    while (s1[i] && s1[i] != '\n') { s2[i] = s1[i]; i++; }
    s2[i] = '\0';
    printf("Copied string: %s", s2);
    return 0;
}
    