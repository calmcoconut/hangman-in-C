#include <stdio.h>

int main()
{
    char *sample = "From whence cometh my help?\n";
    char *s = sample;
    while (putchar(*sample++));
    puts(s);
    return (0);
}