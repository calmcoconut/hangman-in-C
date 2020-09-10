// reverse a string

#include <stdio.h>

char *strrev(char *input);

int main()
{
    char string[64];

    printf("Type some text:  ");
    fgets(string, 62, stdin);
    puts(strrev(string));
    return (0);
}

char *strrev(char *input)
{
    static char output[64];
    char *i, *o;

    i = input;
    o = output;

    while (*i++ != '\n') // put pointer to end
        ;
    i--; // start at end of pointer (gotta not start on the \n char)

    while (i >= input)
    {
        *o++ = *i--; // output = input. input is desc output asc
    }
    *o = '\0'; // make last char of output terminal
    return (output);
}