#include <stdio.h>

float conversion(float faren)
{
    float cel;
    cel = (5.0/9.0) * (faren - 32);
    return cel;
}

int main()
{
    float faren;
    printf("Enter a Temp To Convert: ");
    scanf("%f", &faren);

    printf("The Temp in Fahrenheit is: %.2f and in Celsius is: %.2f\n", faren, conversion(faren));
    return 0;
}
