#include <stdio.h>
#define PI 3.14

// Function declarations
float area_triangle(float b, float h);
float area_circle(float r);
float area_square(float s);

int main() {
    int choice;
    float b, h, r, s;

    printf("Choose shape to find area:\n");
    printf("1. Triangle\n2. Circle\n3. Square\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter base and height: ");
            scanf("%f %f", &b, &h);
            printf("Area of Triangle = %.2f\n", area_triangle(b, h));
            break;

        case 2:
            printf("Enter radius: ");
            scanf("%f", &r);
            printf("Area of Circle = %.2f\n", area_circle(r));
            break;

        case 3:
            printf("Enter side length: ");
            scanf("%f", &s);
            printf("Area of Square = %.2f\n", area_square(s));
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

// Function definitions
float area_triangle(float b, float h) {
    return 0.5 * b * h;
}

float area_circle(float r) {
    return PI * r * r;
}

float area_square(float s) {
    return s * s;
}
