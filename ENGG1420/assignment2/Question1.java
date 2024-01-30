//Author//Author: Aiman Kassam (User ID: 1228282)
//Date Created: 2023-01-23
//Assignment #2, Question #1
//The purpose of this program is to use while loops and if/else statements to print all prime numbers less than 10000.


public class Question1 
{

    public static void main(String[] args) 
    {
        //Variable prime used later in if statements, if prime is true, the number being checked for being prime is printed.
        boolean prime;
        
        //Int 'x' is the number we are checking to see if prime. 
        //'y' is an incrementing number used to check if x fits the conditions of being prime.
        //'y' is unititialized until the loop begins because it will reset to 2 at the start of each number checked.
        int x = 2, y;
        
        //The number in the while loop (in our case 10000) decides up to which number to check for prime numbers.
        //The compound while loops and following if-statements starts by initializing 'y' at checking if x % y leaves a remainder, and incrementing 'y' if it doesn't.
        while(x <= 10000)
        {
            //The boolean 'prime' is initialized to true, and then changed to false if the inner while loop breaks
            prime = true;
            
            //y starts at 2 because since prime numbers are allowed to have 1 as a factor, there is no point in checking for it.
            y = 2;
            while(y < x)
            {
                //If x % y reaches 0 before y reaches x, then x has some factor that is not itself or 1, therefore not being prime, and the loop breaks.
                if(x % y == 0)
                {
                    prime = false;
                    break;
                }
                
                else
                    y++;
                
            }
            //Prints x if it is proven prime by the previous code.
            if(prime != false){
                System.out.println(x);
            }
            //Increments x before starting the next loop, where the new value of x is determined to be prime or not prime.
            x++;
        }
        
        
    }
}
