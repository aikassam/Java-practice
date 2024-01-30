//Author: Aiman Kassam (User ID: 1228282)
//Date Created: 2023-01-11
//Assignment #1, Question #6
//Calls perfectNumber function exactly as defined in Question #5, checks for all numbers between 1 and 1000 to see if they are perfect numbers.
//Since I could not find accurate results on whether or not to include 0, I chose to exclude it since it doesn't technically have any factors.

#include <stdio.h>

//Declaration of perfectNumber function, functions exactly as defined in program for question 5.
int perfectNumber(int num);

void main()
{
    //Variable declared to decide upper bound for numbers that are checked to see if they are perfect numbers. Allows for easy adjustments
    int x = 10000;

    //Checks every number starting at 10000, descends to 0, calls perfectNumber function to see whether the input is a perfect number.
    for(int i = x; i > 0; i++)
    {
        if(perfectNumber(x) == 1)
            printf("%d\n", x);
        x--;
        if(x == 0)
            break;
    }
}

int perfectNumber(int num)
{
    //Sum variable initialized as 0, updated everytime the coming for loop encounters a factor of the number inputted.
    int sum = 0;

    //Checks which numbers are factors of the input by checking if (input % number) is 0, adding the number along if proven true.
    for(int i = 1; i < num; i++)
    {
        if(num % i == 0)
            sum = sum + i;
    }
    //Checks if the sum is equal to the number inputted, as per the definition of a perfect number.
    if(sum == num)
        return 1;
    else
        return 0;
}