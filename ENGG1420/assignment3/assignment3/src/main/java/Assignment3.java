//Author: Aiman Kassam (User ID: 1228282)
//Date: February 6, 2023
//Assignment #3, Question #1 and #2
//In this program, the Rect class is defined with the traits and methods as described in the instructions for Q1 and Q2.
class Rect
{
    //X and Y represent the coordinates of the top-left corner of the rectangle, length and width represent...length and width.
    int X, Y;
    int length, width;
    //Computes the perimeter of the given rectangle.
    int getPerimeter()
    {
        return (2*length + 2*width);
    }
    //Computes the area of the given rectangle.
    int getArea()
    {
        return length * width;
    }
    //Re-assigns the coordinates of the top-left corner of the rectangle.
    void move(int x, int y)
    {
        X = x;
        Y = y;
    }
    //Re-assigns the value of the side lengthws of the rectangle. (Note that the way the assignment asked for this function to be defined always yields a square).
    void changeSize(int n)
    {
        length = n;
        width = n;
    }
    //Prints out all relevant traits of the rectangle by calling its traits and methods.
    void print()
    {
        System.out.println("The coordinates of the top-left corner of this rectangle are (" + X +", " + Y + ")");
        System.out.println("The length of this rectangle is " + length);
        System.out.println("The width of this rectangle is " + width);
        System.out.println("The perimeter of this rectangle is " + getPerimeter());
        System.out.println("The area of this rectangle is " + getArea());
    }
}           
public class Assignment3
{

    public static void main(String[] args)
    {
        //Calls the methods of the rectangle to show the code runs as intended.
        //Certain methods weren't directly called, but were instead called through the print method.
        
        Rect r1 = new Rect();
        
        r1.length = 4;
        r1.width = 6;
        
        r1.print();
        
        System.out.println(" ");
        System.out.println("Above is before values are changed, below is after:");
        System.out.println(" ");
        
        r1.changeSize(9);
        
        r1.move(31,14);
        
        r1.print();
    }
}
