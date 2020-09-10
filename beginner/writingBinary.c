#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *handle;
    int highschore;

    handle = fopen("scores.dat","w");
    if(!handle){
        puts("error!");
        exit(1);
    }
    printf("What is your high schore? ");
    scanf("%d",&highschore);
    fwrite(&highschore,sizeof(int),1,handle);
    fclose(handle);
    puts("Saved");
    return(0);
}