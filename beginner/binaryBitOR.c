#include <stdio.h>
#define SET 32 // IN BINARY THIS IS 100000 SO | OPERATION WILL AFFECT WHERE 1

char *binbin(int n);

int main()
{
    int bor, result;

    printf("Type a value from 0 to 255:  ");
    scanf("%d", &bor);
    result = bor | SET; // where bit is 1 in the SET value, it is 1 in the result.

    printf("\t%s\t%d\n", binbin(bor), bor);
    printf("|\t%s\t%d\n", binbin(SET), SET);
    printf("=\t%s\t%d\n", binbin(result), result);

    return (0);
}

char *binbin(int n)
{
    static char bin[9];
    int x;

    for (x = 0; x < 8; x++)
    {
        bin[x] = n & 0x80 ? '1' : '0';  // 0x80 is hexadecimal for binary 10000000. 0x80 is used for 8-bit numbers logic here is:
                                        // AND mask with the value n, so all but the leftmost bit in the number is discarder. if that bit is set, it makes the condition TRUE, so 1 is stored. otherwise 0 is stored.
        n <<= 1;                        // shift n by 1 bit to the left. as the loops spins, another bit in the value is shitfted to the leftmost position. the bit is evaluated and the binary string is built by inserting '1' or '0'.
    }
    bin[x] = '\0';
    return (bin);
}