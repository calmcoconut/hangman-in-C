#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char chosenWord[25];
int chosenWordLength;
char guessState[25];
int hangState = 2;
char available[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
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
void drawHang(int hangState);
void drawWord();
void drawAvailableLetters();
void initStage();
void makeGuess(char guess);
void checkWinner();

int main()
{
    initStage();
    return (0);
}

void initStage()
{
    processCSV(3);
    drawHang(hangState);
    drawWord();
    drawAvailableLetters();

    while (hangState < 8){
        puts("Make a guess!");
        char g;
        scanf("%c", &g);
        makeGuess(g);
        drawHang(hangState);
        drawWord();
        drawAvailableLetters();
    }
}

void checkWinner()
{
    int isWinner = 1;
    for (int i=0; i<chosenWordLength;i++)
    {
        if (guessState[i]==' '){
            isWinner = 0;
            break;
        }
    }
    if (isWinner){
        puts("You Win!");
        exit(0);
    }
}

void makeGuess(char guess)
{
    int isAvailable = 0;
    for (int i = 0; i < 26; i++)
    {
        if (toupper(guess) == available[i])
        {
            isAvailable = 1;
            available[i] = ' ';
        }
    }
    if (isAvailable)
    {
        int isCorrectGuess = 0;
        char *p = guessState;
        for (int i = 0; i < chosenWordLength; i++)
        {
            if (chosenWord[i] == guess)
            {
                isCorrectGuess = 1;
                p += i;
                *p = guess;
                *p = guessState;
            }
        }

        if (!isCorrectGuess)
        {
            hangState += 1;
        }
    }
    else
    {
        hangState += 1;
    }
}

void drawWord()
{
    printf("\t\t");
    for (int i = 0; i < chosenWordLength; i++)
    {
        printf("%c ", toupper(guessState[i]));
    }
    for (int i = 0; i < chosenWordLength; i++)
    {
        printf("_ ");
    }
}

void drawAvailableLetters()
{
    printf("\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%c ", available[i]);
    }
    puts("\n");
}

void drawHang(int hangState)
{
    for (int i = 0; i < 7; i++)
    {
        printf("%.10s\n", &HANG_STATES[i][hangState * 10]);
    }
    puts("\n");
}

void selectWordFromCSV(char wordArray[][25], int random)
{
    char *p = wordArray[random];
    int count = 1;
    while (*p != '\0')
    {
        count += 1;
        p += 1;
    }
    chosenWordLength = count - 1;
    for (int i = 0; i < count; i++)
    {
        chosenWord[i] = wordArray[random][i];
    }
    printf("Chosen word is %s\nlength is %d\n", chosenWord, chosenWordLength);
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