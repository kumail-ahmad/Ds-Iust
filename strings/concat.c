#include <stdio.h>
int main()
{
    char s1[100], s2[100];
    printf("Enter first string: ");
    fgets(s1, 100, stdin);
    printf("Enter second string: ");
    fgets(s2, 100, stdin);
    int i = 0, j = 0;
    while (s1[i] && s1[i] != '\n')
        i++;
    while (s2[j] && s2[j] != '\n')
    {
        s1[i++] = s2[j++];
    }
    s1[i] = '\0';
    printf("Concatenated string: %s", s1);
    return 0;
}
