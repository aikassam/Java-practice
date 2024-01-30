//Author: Aiman Kassam (User ID: 1228282)
//Date Created: 2023-01-11
//Assignment #1, Question #1
//Takes a user-inputted number, stores it as a string, and returned the number with its digits reversed.

#include <stdio.h>

void main()
{
    //String declared to store number, works better than an integer array since each individual character becomes its own element.
    char num[4];

    printf("Enter a 4-digit number\n");

    //Takes user input.
    scanf("%s", num);
    
    //Prints number in reverse
    printf("Number in reverse: %c%c%c%c", num[3], num[2], num[1], num[0]);
}