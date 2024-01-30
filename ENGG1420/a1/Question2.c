//Author: Aiman Kassam (User ID: 1228282)
//Date Created: 2023-01-11
//Assignment #1, Question #2
//Calculator for performing the simple operations, addition, subtraction, and multiplication on values inputted by the user.

#include <stdio.h>

void main()
{
    //Stores 2 numbers you wish to perform addition, subtraction, or multiplication with.
    double a, b;
    
    //Character to store operation from the following: '+', '-', or '*'.
    char ch;
    
    printf("Enter your first number\n");
    
    scanf("%lf", &a);
    
    printf("Enter your second number\n");
    
    scanf("%lf", &b);
    
    printf("Choose an operation ('+', '-', or '*')\n");

    scanf(" %c", &ch);

    //Series of if statements to perform the operation indicated by the user, returning an error if an invalid option is chosen.
    if(ch == '+')
        printf("The sum is %lf", a + b);
    else if(ch == '-')
        printf("The difference is %lf", a - b);
    else if(ch == '*')
        printf("The product is %lf", a * b);
    else
        printf("Invalid operation.");
}