#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fh;

   fh=fopen("hello.txt","w");
   if(fh==NULL){
       puts("cant open the file");
       exit(1);
   }
   fprintf(fh,"Look What I wrote!\n");
   fclose(fh);
   return(0);
}