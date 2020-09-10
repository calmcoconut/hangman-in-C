#include<stdio.h>

int main()
{
char prompt[] = "Program to Destroy the World \nPress Enter to explode:"; //in C no String type exists. instead use char arrays
    printf("%s", prompt);
    getchar();
    return(0);
    }