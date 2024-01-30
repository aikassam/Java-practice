//Author//Author: Aiman Kassam (User ID: 1228282)
//Date Created: 2023-01-23
//Assignment #2, Question #2
//The purpose of this program is to use for loops and switch-case statements to print all prime numbers less than 10000.

public class Question2 
{

    public static void main(String[] args) 
    {
        //Since switch-cases don't use booleans, I added a new int 'z' and switched 'prime' from boolean to int.
        int x, y, z, prime;
        
        //Initializes x as 2 since it is the lowest prime number. Increments to 10000 checking if any numbers between are prime.
        for(x = 2; x <= 10000; x++)
        {
            //Prime initialized as 1, representing true, will be switched to 0 if a number is not deemed prime.
            prime = 1;
            for(y = 2; y < x; y++)
            {
                z = x % y;
                //Switch case stating if the value of x % y is anything but 0, the number can't be prime since it would have a factor other than 1 or itself.
                switch(z)
                {
                    case 0 -> 
                    {
                        prime = 0;
                        continue;
                    }
                }
            }
            //If by the previous switch statements x is considered prime, it will be printed.
            switch(prime)
            {
                case 1 -> System.out.println(x);
            }
        }
    }
}
