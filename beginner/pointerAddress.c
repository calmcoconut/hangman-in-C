// where is variable stored?

#include <stdio.h>

int main()
{
    char c = 'c';
    int i = 123;
    float f = 98.6;
    double d = 6.022E23;
    char hello[] = "Hello!";

    printf("Address of 'c' %p\n", &c);
    printf("Address of 'i' %p\n", &i);
    printf("Address of 'f' %p\n", &f);
    printf("Address of 'd' %p\n", &d);

    for (int i = 0; i < 7; i++)
    {
        printf("Address of 'c' in array hello %p\n", &hello[i]); // notice, contiguous in memory
    }

    return (0);
}