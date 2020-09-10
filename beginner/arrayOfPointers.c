#include <stdio.h>

int main()
{
    char *fruit[] = {//each string is somewhere in memory. the array just lists where each starts
                     "watermelon",
                     "banana",
                     "pear",
                     "apple",
                     "coconut",
                     "grape",
                     "blueberry"};

    int x;
    for (x = 0; x < 7; x++)
    {
        putchar(**(fruit+x));
        putchar('\n');
    }
    return (0);
}