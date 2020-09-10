// notice you can access array's address with or without & modifier
#include <stdio.h>

int main()
{
    int array[5] = {2, 3, 5, 7, 11};

    printf("'array' is at address %p\n", &array);
    printf("'array' is at address %p (no & sign)\n", array);
    return (0);
}