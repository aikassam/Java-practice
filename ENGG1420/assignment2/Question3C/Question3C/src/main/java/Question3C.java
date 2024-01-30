//Author//Author: Aiman Kassam (User ID: 1228282)
//Date Created: 2023-01-23
//Assignment #2, Question #3-C
//To modify if-statements to print a certain series of symbols if x and y have certain values, and print a different series otherwise.

public class Question3C 
{

    public static void main(String[] args) 
    {
        int x = 5, y = 7;
        
        //Modified if statement to include both conditions in the same statement.
        if(x == 5 && y == 7)
        {
            System.out.println( "#####" );
            System.out.println( "$$$$$" );
            System.out.println( "&&&&&" );
        }
        //Else statement identical to the presented code in the assignment document.
        else
        {
            System.out.println( "@@@@@" );
        }
    }
}
