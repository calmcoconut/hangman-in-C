
#include <stdio.h>

int main()
{
    float temps[5] = {58.7, 62.8, 65.0, 63.3, 63.2};
    float *pt;
    pt = temps;
    // array notation
    printf("The temperature on Tuesday will be %.1f\n", temps[1]);
    printf("The temperature on Friday will be %.1f\n", temps[4]);

    // pointer notation
    printf("The temperature on Monday will be %.1f\n", *pt);
    pt += 3;
    printf("The temperature on Thursday will be %.1f\n", *pt);

    return(0);
}