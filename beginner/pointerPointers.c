#include <stdio.h>

/* key to note that the vars lead and *sidekick share the same memory address.
*  The pointer can also peek into that address and determine the value that is stored there.
*/

int main()
{
    char lead;
    char *sidekick;

    lead = 'A';       // char var
    sidekick = &lead; // init pointer

    printf("About variable 'lead':\n");
    printf("Size\t\t%ld\n", sizeof(lead));
    printf("Contents\t%c\n", lead);
    printf("Location\t%p\n", &lead);
    printf("And variable 'sidekick':\n");
    printf("Contents\t%p\n", sidekick);
    printf("Peek value\t%c\n", *sidekick);

    return (0);
}