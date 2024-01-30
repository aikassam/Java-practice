//Author: Aiman Kassam (User ID: 1228282)
//Date Created: 2023-01-11
//Assignment #1, Question #4
//Takes a value inputted by the user, returns the sum of all of the input's factors, including itself.

#include <stdio.h>

//Declaration of divisorSum function. See code below main function.
int divisorSum(int num);

void main()
{
    //Variable used to store inputted value.
    int num;

    printf("Enter a number:\n");

    scanf("%d", &num);

    //Function called, value of sum of factors is printed.
    printf("The sum of this numbers factors are: %d", divisorSum(num));
}

int divisorSum(int num)
{
    //Sum variable which is updated for every factor found in upcoming for loop.
    int sum = 0;

    //Checks for all possible factors of inputted number using (input % tested-number), adding along each value proven true.
    for(int i = 1; i <= num; i++)
    {
        if(num % i == 0)
            sum = sum + i;
    }

    return sum;
}