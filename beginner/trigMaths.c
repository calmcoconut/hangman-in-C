#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159
#define WAVE 70
#define PERIOD .1

int main()
{
    float graph, s, x;

    for (graph = 0; graph < PI; graph += PERIOD)
    {
        s = sin(graph);
        for (x = 0; x < s * WAVE; x++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    return (0);
}