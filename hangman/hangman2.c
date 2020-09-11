#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char chosenWord;
int chosenWordLength;
static char available[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char HANG_STATES[7][10 * 9] =
    {
        "             +         +----     +----     +----     +----     +----     +----     +----  ",
        "             |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
        "             |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
        "             |         |         |         |   |     |   |     |   |     |   |     |   |  ",
        "             |         |         |         |         |         |         |  /      |  / \\ ",
        "             |         |         |         |         |         |         |         |      ",
        "/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "};

FILE *openWordBankCSV();
void processCSV(int random);
void selectWordFromCSV(char wordArray[][25], int random);

int main()
{
    return (0);
}

void selectWordFromCSV(char wordArray[][25], int random)
{
    char *p = wordArray[random];
    int count = 1;
    while(*p != '\0')
    {
        count +=1;
        p += 1;
    }
    chosenWordLength = count;
    printf("Chosen word is %s",wordArray[random]);
}

void processCSV(int random)
{
    FILE *words = openWordBankCSV();
    char buff[2];
    int wordPos = 0;
    int charPos = 0;
    char wordArray[1200][25];

    while (fgets(buff, 2, words))
    {
        if (buff[0] == ',')
        {
            charPos = 0;
            wordPos += 1;
        }
        else
        {
            if (buff[0] != ' ')
            {
                wordArray[wordPos][charPos] = buff[0];
                charPos += 1;
            }
        }
    }
    fclose(words);
    selectWordFromCSV(wordArray, random);
}


FILE *openWordBankCSV()
{
    FILE *words = fopen("hangman/wordbank.csv", "r");
    if (!words)
    {
        puts("ERROR opening file");
        exit(1);
    }
    return words;
}