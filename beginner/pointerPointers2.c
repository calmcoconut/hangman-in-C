#include <stdio.h>

int main()
{
    char a, b, c;
    char *p;

    a = 'A';
    b = 'B';
    c = 'C';

    int i = 1;
    int *pp;

    printf("Know your ");
    p = &a;      // point the pointer to memory address of char variables
    putchar(*p); // use address for putchar value
    p = &b;
    putchar(*p);
    p = &c;
    putchar(*p);

    printf("s\n");
    printf("int pointers:\n");
    pp = &i;
    printf("value is %d\n", *pp);

    //assigning values with pointer
    b = *p;
    a = *p;
    printf("assigning with pointer is now %c and %c\n", b, a);

    return (0);
}