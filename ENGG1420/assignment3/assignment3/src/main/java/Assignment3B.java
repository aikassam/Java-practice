//Author: Aiman Kassam (User ID: 1228282)
//Date: February 6, 2023
//Assignment #3, Question #3 and #4
//This program defines the Date class as per Assignment #3 instructions for Q3 and Q4.

class Date{
    //Integer values that store the month, day, and year in number-form.
    int day, month, year;
    //prints the date in YYYY/MM/DD format.
    void print()
    {
        System.out.println("The date is " + year + "/" + month + "/" + day );
    }
    //Function to add any given number of days to the current date and re-assign the values accordingly.
    void addDays(int n)
    {
        for(int i = 0; i < n; i++)
        //The following series of if-statements categorizes each month based on how many days they have, re-assigning the day, month, and year accordingly if the month/year is ending.
        {
            if(month == 12)
            {
                if(day == 31)
                {
                    year = year + 1;
                    month = 1;
                    day = 1;
                }
                else
                    day = day + 1;
            }
            else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
            {
                if(day == 31)
                {
                    month = month + 1;
                    day = 1;
                }
                else
                    day = day + 1;
            }
            else if(month == 4 || month == 6 || month == 9 || month == 11)
            {
                if(day == 30)
                {
                    month = month + 1;
                    day = 1;
                }
                else
                    day = day + 1;
            }
            else if(month == 2)
            {
                if(year % 4 == 0)
                {
                    if(day == 29)
                    {
                        month = month + 1;
                        day = 1;
                    }
                    else
                        day = day + 1;
                }
                else
                {
                    if(day == 28)
                    {
                        month = month + 1;
                        day = 1;
                    }
                    else
                        day = day + 1;
                }
            }
        }
    }
    //Method to compare two dates (NOTE: this function only works if the date calling the method is BEFORE the date inputted)
    int compare(Date d)
    {
        int x = 0;
        if(year <= d.year && month <= d.month && day <= d.day)
        {
            for(int i = 0; year <= d.year && month <= d.month && day <= d.day; i++)
            {
                addDays(1);
                x = i;
            }
        }
        return x;
    }
}
public class Assignment3B 
{
    public static void main(String[] args)
    {
        //Declaring two dates and showing off their functionality by calling their methods.
        Date d1 = new Date();
        Date d2 = new Date();
        
        d1.day = 20;
        d1.month = 2;
        d1.year = 2020;
        
        d2.day = 8;
        d2.month = 2;
        d2.year = 2020;
        
        d1.print();
        d2.print();
        
        int x = d2.compare(d1);
        System.out.println("These two dates are "+ x + " days apart.");
    }
}
