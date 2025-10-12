#include <stdio.h>
int main()
{
    char s1[100], s2[100];
    printf("Enter first string: ");
    fgets(s1, 100, stdin);
    printf("Enter second string: ");
    fgets(s2, 100, stdin);
    int i = 0, flag = 0;
    while (s1[i] && s2[i] && s1[i] != '\n' && s2[i] != '\n')
    {
        if (s1[i] != s2[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag)
        printf("Strings are not equal\n");
    else
        printf("Strings are equal\n");
    return 0;
}
