#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct stock{
        char symbol[5];
        int quantity;
        float price;
    };
    struct stock *invest;
    // create struct in memory
    invest =(struct stock*)malloc(sizeof(struct stock));
    if(invest==NULL){
        puts("Out of Memory");
        exit(1);
    }
    // init struct data
    strcpy(invest->symbol,"GOOG");
    invest->quantity=100;
    invest->price=801.19;

    // display db
    puts("Portfolio is:");
    printf("Symbol\tShares\tPrice\tValue\n");
    printf("%-6s\t%5d\t%.2f\t%.2f\n",\
    invest->symbol,
    invest->quantity,
    invest->price,
    invest->quantity*invest->price);
    return(0);
}