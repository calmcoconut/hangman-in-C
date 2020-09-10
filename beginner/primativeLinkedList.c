#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    struct stock{
        char symbol[5];
        int quantity;
        float price;
        struct stock *next;
    };
    struct stock *first;
    struct stock *current;
    struct stock *new;
    // create structure in memory
    first=(struct stock*)malloc(sizeof(struct stock));
    if (first==NULL){
        puts("Out of memory");
        exit(1);
    }
    // init struct data
    current =first;
    strcpy(current->symbol,"GOOG");
    current->quantity=100;
    current->price=801.19;
    current->next=NULL;

    new = (struct stock*)malloc(sizeof(struct stock));
    if(new==NULL){
        puts("out of memory");
        exit(1);
    }
    current->next=new;
    current=new;
    strcpy(current->symbol,"MSFT");
    current->quantity=100;
    current->price=28.77;
    current->next=NULL;

    // dis db
    puts("Portfolio");
    printf("Symbol\tShares\tPrice\tValue\n");
    current=first;
    while(1){
    printf("%-6s\t%5d\t%.2f\t%.2f\n"
    ,current->symbol
    ,current->quantity
    ,current->price
    ,current->quantity * current->price
    );
    if(current->next == NULL){
        break;
    }
    current = current->next;
    }
    exit(1);
}