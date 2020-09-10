#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *temp;
    int *isCelsius;

    temp = (float *)malloc(sizeof(float) * 1);
    isCelsius = (int *)malloc(sizeof(int) * 1);
    if (temp == NULL || isCelsius == NULL)
    {
        puts("unable to allocate memory");
        exit(1);
    }
    printf("What is the current temperature outside?");
    scanf("%f", temp);
    printf("Celsius write 1. Fahrenheit write 0.\n");
    scanf("%d", isCelsius);
    if (isCelsius)
    {
        printf("Kelvin is currently %f", *temp + 273.15);
    }
    else
    {
        printf("Kelvin is currently %f", (*temp + 459.67) * (5.0 / 9.0));
    }
    return (0);
}