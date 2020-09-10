// how big is a variable?
/*
* sizeof is more of an operator. the value it returns is known as size_t.
* size_t is a typedef of another variable type. it indicated the number of bytes used to store a variable.
*/
#include <stdio.h>

struct robot {
    int alive;
    char name[5];
    int xpos;
    int ypos;
    int strength;
};

int main()
{
    char c = 'c';
    int i = 123;
    float f = 98.6;
    double d = 6.022E23;
    char string[] = "does this string make me look fat?";
    int nums[] = {1,2,3};

    printf("char\t%u\n", sizeof(c));
    printf("int\t%u\n", sizeof(i));
    printf("float\t%u\n", sizeof(f));
    printf("double\t%u\n", sizeof(d));
    printf("char array\t%u\n", sizeof(string));
    printf("int array\t%u\n", sizeof(nums));
    printf("robot struct \t%u\n", sizeof(struct robot));

    return (0);
}