#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *input;
    int len;

    input = (char *)malloc(sizeof(char) * 1024);
    if (input == NULL)
    {
        puts("Unable to allocate Buffer!");
        exit(1);
    }
    puts("Type something long!");
    fgets(input, 1023, stdin);
    len = strlen(input);
    if (realloc(input, sizeof(char) * (len + 1)) == NULL)
    {
        puts("Unable to reallocate buffer");
        exit(1);
    }
    puts("Memory reallocated.");
    puts("You wrote:");
    printf("\"%s\"\n", input);

    return (0);
}