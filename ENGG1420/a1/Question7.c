//Author: Aiman Kassam (User ID: 1228282)
//Date Created: 2023-01-11
//Assignment #1, Question #7
//Declares, defines, and tests two functions, each taking the newely defined Date structure as inputs.
//The function 'getNextDate' takes a date as input, returns the day immediately following.
//The function 'compareDate' takes 2 dates as input, returns 1, 0, or -1 based on if the the first date parameter is later, the same as, or before the second date respectively.

#include <stdio.h>
//Defined structure for Date with integer day, month, and year members as per instructions.
struct Date
{
    int day;
    int month;
    int year;
};

//Declaration of function that returns the next date. See code for function below main function.
struct Date getNextDate(struct Date x);

//Declaration of function to check whether or not two dates are the same. Returns 0 if they're the same, +1 if the first date is later, -1 if the second date is later.
int compareDate(struct Date x, struct Date y);

//Main function where designed functions are tested using inputted dates from the user.
void main()
{
    //Declared variables, today stores the inputted date from the user, tomorrow will store data for the next day after getNextDate function is called.
    struct Date today, tomorrow;

    printf("Enter the date in the following format: MM/DD//YYYY\n");

    //To recieve user input.
    scanf("%d/%d/%d", &today.month, &today.day, &today.year);
    
    //Calling getNextDate function.
    tomorrow = getNextDate(today);
    
    //Print statement used to test for accuracy of results
    printf("Tomorrow is %.2d/%.2d/%.4d.\n", tomorrow.month, tomorrow.day, tomorrow.year);

    //The following print statements are purely to show that the compareDate function works as intended. Should print -1, then 0, then 1, which would be the intended outputs based on the parameters I put in.
    printf("%d\n", compareDate(today, tomorrow));
    
    printf("%d\n", compareDate(today,today));
    
    printf("%d\n", compareDate(tomorrow,today));
}
struct Date getNextDate(struct Date x)
{
    //Additional Date structure declared to store information for the next day.
    struct Date y;
    //Series of extensive if statements, changing variable assignments based on the month due to months with 28, 30, or 31 days. Resets day value to 1 when the end of the month is reached. If it is not the end of the month or year, increments day by 1.
    //If statements used for end of February
    if(x.month == 2)
    {
        if(x.day == 28)
        {
            y.month = x.month + 1;
            y.day = 1;
            y.year = x.year;
        }
        else
        {
            y.day = x.day + 1;
            y.month = x.month;
            y.year = x.year;
        }
    }
    //If statements used for end of January, March, May, July, August, and October (31 day months)
    else if(x.month == 1 || x.month == 3 || x.month == 5 || x.month == 7 || x.month == 8 || x.month == 10)
    {
        if(x.day == 31)
        {
            y.month = x.month + 1;
            y.day = 1;
            y.year = x.year;
        }
        else
        {
            y.day = x.day + 1;
            y.month = x.month;
            y.year = x.year;
        }
    }
    //If statements used for April, June, September, and November (30 day months)
    else if(x.month == 4 || x.month == 6 || x.month == 9 || x.month == 11)
    {
        if(x.day == 30)
        {
            y.month = x.month + 1;
            y.day = 1;
            y.year = x.year;
        }
        else
        {
            y.day = x.day + 1;
            y.month = x.month;
            y.year = x.year;
        }
    }
    //If statement used for December, categorized separately to declare a new year.
    else if(x.month == 12)
    {
        if(x.day == 31)
        {
            y.year = x.year + 1;
            y.month = 1;
            y.day = 1;
        }
        else
        {
            y.day = x.day + 1;
            y.month = x.month;
            y.year = x.year;
        }
    }
    return y;
}
int compareDate(struct Date x, struct Date y)
{
//Series of compound if statements for comparing date. 
    //Checks for whether the year is the same, before or after.
    if(x.year == y.year)
    {
        //Checks if the month is the same, before, or after.
        if(x.month == y.month)
        {
            //Checks if the day is the same, before, or after.
            if(x.day == y.day)
            {
                return 0;
            }
            else if(x.day > y.day)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if(x.month > y.month)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }else if(x.year > y.year)
    {
        return 1;
    }
    else
    {
        return -1;
    }
//Returns 1 if overall date of the first parameter is after the second, 0 if they are the same, -1 if before.
}
