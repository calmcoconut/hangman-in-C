// iterating a pointer
#include <stdio.h>

int main()
{
    int numbers[10];
    int x;
    int *pn;

    pn = numbers;            // init pointer... & not needed sense array is inherently a pointer
    for (x = 0; x < 10; x++) // fill array using pointer
    {
        *pn = x + 1;         // *pn begins with base value 0, then goes to next element of array
        pn++;
    }
    pn = numbers;
    //display array
    for (x = 0; x < 10; x++)
    {
        printf("numbers[%d] = %d address: %p\n", x + 1, numbers[x], pn); // notice addressincrements by a unit, bits in the case of an int.
        pn++;
    }
    return(0);
}