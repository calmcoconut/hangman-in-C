#include <stdio.h>

int main() {
    char sample[] = "From whence cometh my help?\n";
    char *pc = sample;
    int index = 0;

    while(*pc){
        putchar(*pc++);
    }
    return(0);
}