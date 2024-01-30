//Author//Author: Aiman Kassam (User ID: 1228282)
//Date Created: 2023-01-23
//Assignment #2, Question #4
//Calculator that takes user input for numbers, taking the sum of all the numbers you enter in a loop, breaking when you enter 0 and printing the sum.

//Requried to allow user input.
import java.util.Scanner;
public class Question4 {

    public static void main(String[] args) 
    {
        //Sets variable to be called whenever we want to take user input.
        Scanner scan = new Scanner(System.in);
        
        //Initialize variables to hold total sum that's printed later and user input.
        double sum = 0, num;
        
        //while loop that will run until broken using the if statement embedded in it.
        while(true)
        {
            //Adds every number entered into the total sum until 0 is entered.
            System.out.println("Enter a number to add: ");
            num = scan.nextDouble();
            sum = sum + num;
            if(num == 0)
                break;
        }
        //Prints the total sum.
        System.out.println("The sum of the numbers you entered is: " +sum);
    }
}
