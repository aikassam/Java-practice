#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 128
#define MAX_WORDS_PER_LINE 128
#define MAX_NUM_LINES 10

struct Player
{
    char playerName[MAX_STRING_SIZE];
    int goals;
    int assists;
    int points;
    char nationality[MAX_STRING_SIZE];
};

int splitLineIntoStrings(char line[], 
                        char words[][MAX_STRING_SIZE], 
                        char seperators[]);
int readLine(char line[], int size, FILE* fp);

int main(){
    FILE *fp = fopen("lab9.csv", "r");
    if(fp == NULL){
        printf("Error opening file.\n");
        return -1;
    }
    //makes a stucture array that stores all players as "Puckbunnies"
    struct Player Puckbunnies[255];

    /*
    char players[MAX_NUM_LINES][MAX_STRING_SIZE];
    int goals[MAX_NUM_LINES];
    int assists[MAX_NUM_LINES];
    int points[MAX_NUM_LINES];
    */
    int curIndex = 0;

    char year[MAX_STRING_SIZE];
    char team[MAX_STRING_SIZE];

    fgets(year, MAX_STRING_SIZE, fp);
        
    printf("%s", year);

    fgets(team, MAX_STRING_SIZE, fp);
        
    printf("%s", team);
   
    while(!feof(fp)){
        char line[MAX_STRING_SIZE];
        char fields[MAX_WORDS_PER_LINE][MAX_STRING_SIZE];


        readLine(line, MAX_STRING_SIZE, fp);

        // int numFields = splitLineIntoStrings(line, fields, ",");
        // numFields can be used in a for loop -- for(int i = 0; i < numFields; i++)
        // In this case however we have a small number of fields and it's a little bit more striaghtforward to manually deal with the four fields
        // Thus we do not need to save the return value from the function
        splitLineIntoStrings(line, fields, ",");

        strcpy(Puckbunnies[curIndex].playerName, fields[0]);
        strcpy(Puckbunnies[curIndex].nationality, fields[1]);
        Puckbunnies[curIndex].goals = atoi(fields[2]);
        Puckbunnies[curIndex].assists = atoi(fields[3]);
        Puckbunnies[curIndex].points = atoi(fields[4]);

        curIndex++;
    }

    fclose(fp);

    char input[MAX_STRING_SIZE] = "";
    printf("Search for player name: ");
    scanf("%s", input);

    /*for(int j = 0; j < curIndex; j++)
    {
        printf("%s %s %d %d %d\n", Puckbunnies[j].playerName, Puckbunnies[j].nationality, Puckbunnies[j].goals, Puckbunnies[j].assists, Puckbunnies[j].points);
    }*/

    while(strcmp(input, "exit") != 0){
        int playerFound = 0;

        for(int i = 0; i < MAX_NUM_LINES; i++){
            if(strcmp(Puckbunnies[i].playerName, input) == 0){
                printf("%s has scored %d goals, has %d, and has %d this season\n",Puckbunnies[i].playerName, Puckbunnies[i].goals, Puckbunnies[i].assists, Puckbunnies[i].points);
                playerFound = 1;
                break;
            }
        }
        if(!playerFound){
            printf("%s does not exist in this dataset, please search for a different player\n", input);
        }
        printf("\n");

        printf("Search for player name: ");
        scanf("%s", input);
    }
}

/* splitLineIntoStrings
 *  Description: takes a string and separates it into many substrings stored in
 * an array of strings called words.
 *  Inputs:
 *      - line: the string which will be separated
 *      - words: this array will be filled with strings. They are substrings of line
 *      - seperators: the characters that will split the data. Ec. "," or " ,."
 * 
 *  Return:
 *      - int: the number of substrings (words) found and put in the words array
*/ 
int splitLineIntoStrings(char line[], 
                        char words[][MAX_STRING_SIZE], 
                        char seperators[]){
    int wordCount = 0;

    // use same tokenizer from before
    char *token = strtok(line, seperators);

        while (token != NULL){
            //printf("funN: %s\n", token);
            strcpy(words[wordCount], token);
            
            token = strtok(NULL, seperators);
            wordCount++;
        }
    // use strcpy to copy token into array

    return wordCount;
}

/* readLine
 *  Description: reads a the next line of text from a file and saves it in
 *  a string called line.
 *  Inputs:
 *      - line: a string which will be filled with the data from the next line of the file.
 *      - size: the maximum number of characters to read.
 *      - fp:   the file to read from.
 *  Return:
 *      - int: 1 if a line is read. 0 if the line cannot be read.
*/ 
int readLine(char line[], int size, FILE* fp){
    // check that the file exists, and we are not at the end
    if(fp == NULL || feof(fp)){ 
        return 0;
    }

    // read the next line of the file into the string line
	fgets(line, size, fp); 

	// fgets leaves a '\n' at the end of the string, the next line will remove it.

    // CHECK IF A NEWLINE CHARACTER WAS READ IN WITH THE gets() BEFORE IT IS REPLACED
    if(line[strlen(line) -1] == '\n'){
        line[strlen(line) -1] = '\0';
    }

    return 1;
}