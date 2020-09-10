// masking bits using &

#include <stdio.h>
#define SET 223 // IN BINARY THIS IS 11011111 SO & OPERATION WILL AFFECT WHERE 0

char *binbin(int n);

int main()
{
    int bor, result;

    printf("Type a letter from a - z:  ");
    scanf("%c", &bor);
    result = bor & SET;

    printf("\t%s\t%d\n", binbin(bor), bor);
    printf("&\t%s\t%d\n", binbin(SET), SET);
    printf("=\t%s\t%d\n", binbin(result), result);

    return (0);
}

char *binbin(int n)
{
    static char bin[9];
    int x;

    for (x = 0; x < 8; x++)
    {
        bin[x] = n & 0x80 ? '1' : '0';
        n <<= 1;
    }
    bin[x] = '\0';
    return (bin);
}