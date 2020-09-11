#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/*
TODO
1. word selection
2. draw stage
3. correct guess behavior
4. incorrect guess behavior
5. restart game

*/
char *initWord();
char *initStage(char *word, char letters[]);
void drawHang(int currentState);
char *drawWord(char *randomWord, char *answer);
void drawAvailableLetters(char letters[]);
int makeGuess(char *randomWord, char *guessSaved, char currentGuess);
void checkWinner(char *guessSaved);
FILE *openWordBankFile();
char *processCSV();

static char available[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int main()
{
    char *randomWord = initWord();
    char *guess = initStage(randomWord, available);

    int hangState = 2;
    while (hangState != 8)
    {
        printf("\nGuess a letter!\n");
        char currentGuess;
        scanf("%c",&currentGuess);
        int result = makeGuess(randomWord,guess,currentGuess);
        if (result){

        }
        else {
            hangState += 1;
        }
            drawHang(hangState);
            drawWord(randomWord, guess);
            drawAvailableLetters(available);
    }
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
        "/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "};

char *initStage(char *word, char letters[])
{
    drawHang(2);
    char *blanks = "                                          ";
    char *guess = drawWord(word, blanks);
    drawAvailableLetters(letters);
    return (guess);
}

int makeGuess(char *randomWord, char *guessSaved, char currentGuess)
{
    int isAvailableToGuess = 0;
    int isCorrectGuess = 0;

    for (int i = 0; i < 26; i++)
    {
        if ((int)available[i] == toupper(currentGuess))
        {
            isAvailableToGuess = 1;
        }
    }

    if (isAvailableToGuess)
    {
        int correct[25];
        int counter = 0;
        while (*randomWord != '\0')
        {
            if ((int)*randomWord == tolower(currentGuess))
            {
                correct[counter] = 1;
                isCorrectGuess = 1;
            }
            counter += 1;
            randomWord += 1;
        }

        if (isCorrectGuess)
        {
            for (int i = 0; i < 25; i++)
            {
                if (correct[i] == 1)
                {
                    guessSaved += i;
                    *guessSaved = toupper(correct[i]);
                }
            }
            return(1);
        }
    }
    return(0);
}

void checkWinner(char *guessSaved){
    int isWinner = 1;
    while(*guessSaved){
        if (*guessSaved == ' '){
            isWinner = 0;
        }
        guessSaved +=1;
    }
    if (isWinner){
        printf("WINNER");
        exit(0);
    }
}

void drawHang(int currentState)
{
    for (int i = 0; i < 7; i++)
    {
        printf("%.10s\n", &HANG_STATES[i][currentState * 10]);
    }
    puts("\n");
}

char *drawWord(char *randomWord, char *answer)
{
    printf("\t\t");
    int lengthArray = 0;
    while (*randomWord != '\0')
    {
        lengthArray += 1;
        randomWord += 1;
    }

    char *guess = malloc(lengthArray + 1 * sizeof(char));
    for (int i = 0; i < lengthArray; i++)
    {
        printf("%c ", *answer);
        guess[i] = " ";
        answer += 1;
    }
    printf("\n\t\t");
    for (int i = 0; i < lengthArray; i++)
    {
        printf("_ ");
    }
    return (guess);
}

void drawAvailableLetters(char letters[])
{
    printf("\n\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%c ", letters[i]);
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