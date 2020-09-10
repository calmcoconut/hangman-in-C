#include <stdio.h>

int main()
{
    int first = 'A';
    int second = 'A';
    int third = 'A';
    
    while (first + second + third != 'Z' * 3)
    {
        printf("%c%c%c\t", first, second, third);

        if (third != 'Z')
        {
            third++;
        }
        if (third == 'Z')
        {
            if (second != 'Z')
            {
                second++;
                third = 'A';
                putchar('\n');
            }
            else
            {
                first++;
                second, third = 'A';
            }
        }
    }

    return (0);
}