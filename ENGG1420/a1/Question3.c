//Author: Aiman Kassam (User ID: 1228282)
//Date Created: 2023-01-11
//Assignment #1, Question #3
//Takes 5 integer numbers as inputs, stores them in an array, and prints both the smallest and largest values in the array.

#include <stdio.h>

void main()
{
    //Decides how many numbers to compare to find largest and smallest amongst set. Setting as variable allows for easy changes as user sees fit. Set to 5 as per assignment instructions.
    int num = 5;

    //Array of integers to store numbers you wish to compare
    int array[num];

    printf("Enter %d numbers one at a time\n", num);

    //Scans for a number once for each element of array.
    for(int i = 0; i < num; i++)
        scanf("%d", &array[i]);

    //Variables that will store max and min values of functions, initialized to first element of array because all elements will be compared to each other in for loop.
    int max = array[0], min = array[0];

    //Everytime a bigger number is found, updates the max value.
    for(int j = 0; j < num; j++)
    {
        if(array[j] > max)
            max = array[j];
    }

    printf("The largest number you entered is %d\n", max);

    //Everytime a smaller number is found, updates the min value.
    for(int k = 0; k < num; k++)
    {
        if(array[k] < min)
            min = array[k];
    }

    printf("The smallest number in the array is %d", min);
}