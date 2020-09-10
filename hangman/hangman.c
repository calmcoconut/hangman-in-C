#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
TODO
1. word selection
2. draw stage
3. correct guess behavior
4. incorrect guess behavior
5. restart game

*/
char *initWord();
char *readWordData();
void initStage();
FILE *openWordBankFile();
char *processCSV(FILE *);

int main()
{
    initWord();
    exit(0);
}

char *initWord()
{
    char **words = processCSV(openWordBankFile);
    int random = rand() % 1000;
    printf("%d",random);
}

char *readWordData()
{
}

char *processCSV(FILE *words)
{
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
            if (buff[0] == ' ')
            {
                continue;
            }
            else
            {
                wordArray[wordPos][charPos] = buff[0];
                charPos += 1;
            }
        }
    }
    fclose(words);

    return(wordArray);
}

FILE *openWordBankFile()
{
    FILE *words = fopen("hangman/wordbank.csv", "r");
    if (!words)
    {
        puts("error opening file");
        exit(1);
    }
    return words;
}