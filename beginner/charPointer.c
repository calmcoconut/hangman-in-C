#include <stdio.h>

int main() {
    char alpha = 'A';
    int x;
    char *pa;

    pa = &alpha;

    for (x=0;x<26;x++){
        putchar((*pa)++); // increments the value being peeked at.. the pointer does not change.
    }
        putchar('\n');
    return(0);
}