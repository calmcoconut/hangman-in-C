#include <stdio.h>

int main()
{
    char *fruit[] = {
        "apricot",
        "banana",
        "pineapple",
        "apple",
        "persimmon",
        "pear",
        "blueberry"};
    char *temp;
    int a, b, x, val;

    for (a = 0; a < 6; a++)
    {
        for (b = a + 1; b < 7; b++)
        {
            val = strcmp(*(fruit + a), *(fruit + b)); // you cannot use > to compare strings.
            if (val > 0)
            {
                
                temp = *(fruit + a);
                *(fruit + a) = *(fruit + b);
                *(fruit + b) = temp;
            }
        }
    }
    for (x = 0; x < 7; x++)
    {
        puts(fruit[x]);
    }
    return (0);
}