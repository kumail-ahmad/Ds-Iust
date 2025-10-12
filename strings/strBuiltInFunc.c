#include <stdio.h>
#include <string.h>
int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[50];

    // 1. Length
    printf("Length of str1: %lu\n", strlen(str1));

    // 2. Concatenate
    strcat(str1, str2);
    printf("After concatenation: %s\n", str1);

    // 3. Reverse
    strrev(str1);
    printf("Reversed string: %s\n", str1);

    // 4. Comparison
    int cmp = strcmp("abc", "abd");
    if (cmp == 0)
        printf("Strings are equal\n");
    else if (cmp < 0)
        printf("First is smaller\n");
    else
        printf("First is greater\n");

    // 5. Copy
    strcpy(str3, "Copied text");
    printf("Copied string: %s\n", str3);
}
