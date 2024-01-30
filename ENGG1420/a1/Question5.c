//Author: Aiman Kassam (User ID: 1228282)
//Date Created: 2023-01-11
//Assignment #1, Question #5
//Uses perfectNumber function to check an user-inputted value. 
//If the sum of the input's factors, NOT including itself, is equal to the input itself, the input is a perfect number.
//SIDE NOTE: I could not find consistent answers online as to whether or not 0 is a perfect number or not.

#include <stdio.h>

//Declaration of perfect number function, similar to divisorSum function, except that the number inputted itself does not get added.
int perfectNumber(int num);

void main()
{
    //Stores the number taken from user input to check if it's a perfect number.
    int num;

    printf("Enter a number:\n");

    scanf("%d", &num);

    //Prints whether or not the input is a perfect number based off whether the value 0 or 1 is returned.
    if(perfectNumber(num) == 1)
        printf("%d is a perfect number.", num);
    else
        printf("%d is NOT a perfect number.", num);
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