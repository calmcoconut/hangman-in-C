#include <stdio.h>

int main() {
    char firstname[15];

    printf("Tye your first name please: ");
    scanf("%s", firstname);
    printf("Nice to meet you %s.\n", firstname);

    printf("OK. what is your favorite number, %s\n", firstname);
    int favNum;
    scanf("%d", &favNum); // here we use & to use the pointer of the argument
    printf("%d is a great number!", favNum);

    return(0);
}