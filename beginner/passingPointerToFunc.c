#include <stdio.h>

void discount(float *a);

int main()
{
    float price = 42.99;
    float *p = &price;

    printf("The item costs $%.2f\n", price);
    discount(p);

    printf("With the discount, it's now $%.2f\n", price);
    return(0);
}

void discount(float *a) {
    *a = *a * 0.9;
}