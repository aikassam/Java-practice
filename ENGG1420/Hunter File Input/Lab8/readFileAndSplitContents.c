/* readFileAndSplitContents.c
 * Description: This program reads in a file, and splits the contents of each 
 * line into substrings (tokens). The tokens are then printed to the dispaly.
 * 
 * Arguments: 
 *      - filename: the name of the file that will be opened.
 * 
 * Compile:
gcc -std=c99 -Wall readFileAndSplitContents.c 

 * Run:
./a.out myfile.txt
*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 128
#define MAX_WORDS_PER_LINE 128
#define MAX_NUM_LINES 5

int readLine(char line[], int size, FILE* fp);
int splitLineIntoStrings(char line[], char words[][MAX_STRING_SIZE], char seperators[]);

int main(int argc, char* argv[]) {
    if(argc < 2){
        printf("Invalid arguments\nPlease enter filename\n");
        return -1;
    }
    char players[MAX_STRING_SIZE][MAX_STRING_SIZE];
    int kills[MAX_STRING_SIZE];
    int deaths[MAX_STRING_SIZE];
    int assists[MAX_STRING_SIZE];
    // get filename from Command Line Argument
    char filename[MAX_STRING_SIZE]; strcpy(filename, argv[1]); 
    FILE *fp; // create file pointer 
    fp = fopen(filename, "r"); // open the dest file to WRITE

    char data[MAX_NUM_LINES][MAX_WORDS_PER_LINE][MAX_STRING_SIZE] = {0};

    int i = 1;

    if(fp == NULL){ // check that the file opened
        printf("ERROR: Files %s does not exist\n", filename);
        return -1;
    }
    else{
        while(!feof(fp)){ // keep reading until end of file
            char line[MAX_STRING_SIZE]; 
            char words [MAX_WORDS_PER_LINE][MAX_STRING_SIZE]; 

            readLine(line, MAX_STRING_SIZE, fp);
            printf("LINE:\t%s\n", line);

            int numWords = splitLineIntoStrings(line, words, ",");

            strcpy(players[i], words[0]);
            kills[i] = atoi(words[1]);
            deaths[i] = atoi(words[2]);
            assists[i] = atoi(words[3]);
            i++;
        }
    }
    for(int j = 0; j < i; j++)
    {
        printf("%s %d %d %d\n", players[j], kills[j], deaths[j], assists[j]);
    }
    fclose(fp); // close the file
    
    return 0;
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

        while (token != NULL)
        {
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
	line[strlen(line) -1] = '\0';

    return 1;
}
