#include "stdio.h" 
#include "stdlib.h"
#include "string.h"
#include "time.h"

/*
TODO
1. word selection
2. draw stage
3. correct guess behavior
4. incorrect guess behavior
5. restart game

*/
char *initWord();
void initStage();
void drawHang(int currentState);
void drawBlankWord(char *randomWord);
void drawAvailableLetters(char letters[]);
FILE *openWordBankFile();
char *processCSV();

int main() { 
    char *randomWord = initWord(); 
    char available[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','T','U','V','W','X','Y','Z'}; 
    initStage(); 
    drawBlankWord(randomWord); 
    drawAvailableLetters(available); 
    exit(0);
   }

char HANG_STATES[7][10 * 9] = 
{
	"             +         +----     +----     +----     +----     +----     +----     +----  ",
	"             |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
	"             |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
	"             |         |         |         |   |     |   |     |   |     |   |     |   |  ",
	"             |         |         |         |         |         |         |  /      |  / \\ ",
	"             |         |         |         |         |         |         |         |      ",
	"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "
};

void initStage()
{
    drawHang(3);
}

void drawHang(int currentState)
{
    for (int i = 0; i < 7; i++)
    {
        printf("%.10s\n", &HANG_STATES[i][currentState * 10]);
    }
    puts("\n");
}

void drawBlankWord(char *randomWord)
{
    printf("\t\t");
    while(*randomWord != '\0'){
        printf("_ ");
        randomWord+=1;
    }
}

void drawAvailableLetters(char letters[])
{
    int length = sizeof letters / *letters;
    for (int i = 0; i < length; i++)
    {
        if (i == 10)
        {
            printf("\n");
        }
        printf(letters[i]);
    }
}
char *initWord()
{
    srand(time(0));
    int random = rand() % 1000;
    printf("%d\n", random);
    char *randomWord = processCSV(random);
    printf("random word is %s\n", randomWord);
    return (randomWord);
}

char *processCSV(int random)
{
    FILE *words = openWordBankFile();
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

    int count = 1;
    for (int i = 0; i < sizeof wordArray[random]; i++)
    {
        if (wordArray[random][i] != '\0')
        {
            count += 1;
        }
    }
    char randomWord[count];
    for (int i = 0; i < sizeof wordArray[random]; i++)
    {
        if (wordArray[random][i] != '\0')
        {
            randomWord[i] = wordArray[random][i];
        }
    }
    randomWord[count - 1] = '\0';
    char *c = randomWord;
    return (c);
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