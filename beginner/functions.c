#include <stdio.h>

void prompt();

int main() {
    int i = 0;
    while (i<5) {
        prompt();
        i++;
    }
    return(0);
}

void prompt() {
    printf("my monkey...");
}