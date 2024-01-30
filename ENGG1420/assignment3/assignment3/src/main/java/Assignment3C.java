//Author: Aiman Kassam (User ID: 1228282)
//Date: February 6, 2023
//Assignment #3, Question #5 and #6
//In this program, the Rect class is defined with the traits and methods as described in the instructions for Q5 and Q6.
class Rect
{
    //All traits are assigned a public access modifer since there are no privacy risks with this program.
    
    //X and Y represent the coordinates of the top-left corner of the rectangle, length and width represent...length and width.
    public int X, Y;
    public int length, width;
    
    //Computes the perimeter of the given rectangle.
    public int getPerimeter()
    {
        return (2*length + 2*width);
    }
    
    //Computes the area of the given rectangle.
    public int getArea()
    {
        return length * width;
    }
    
    //Re-assigns the coordinates of the top-left corner of the rectangle.
    public void move(int x, int y)
    {
        X = x;
        Y = y;
    }
    
    //Re-assigns the value of the side lengthws of the rectangle. (Note that the way the assignment asked for this function to be defined always yields a square).
    public void changeSize(int n)
    {
        length = n;
        width = n;
    }
    
    //Prints out all relevant traits of the rectangle by calling its traits and methods.
    public void print()
    {
        System.out.println("The coordinates of the top-left corner of this rectangle are (" + X +", " + Y + ")");
        System.out.println("The length of this rectangle is " + length);
        System.out.println("The width of this rectangle is " + width);
        System.out.println("The perimeter of this rectangle is " + getPerimeter());
        System.out.println("The area of this rectangle is " + getArea());
    }
    
    //Allows for Rectangles to be intialized with their length and width.
    Rect(int a, int b)
    {
        if(a < 0)
            a = -a;
        if(b < 0)
            b = -b;
        if(a == 0)
            a = 1;
        if (b == 0)
            b = 1;
        length = a;
        width = b;
    }
    
    //Allows for Rectangles to be initialized with their length, width, and coordinates
    Rect(int a, int b, int c, int d)
    {
        if(a < 0)
            a = -a;
        if(b < 0)
            b = -b;
        if(a == 0)
            a = 1;
        if (b == 0)
            b = 1;
        length = a;
        width = b;
        X = c;
        Y = d;
    }
    
    //Compares the areas of the two rectangles, if the caller has greater area, returns true. If the input has greater area, returns false.
    boolean isBiggerThan(Rect r)
    {
        int x = getArea();
        int y = r.getArea();
        return x > y;
    }
}   
public class Assignment3C 
{
    public static void main(String[] args)
    {
        //Calls the methods of the rectangle to show the code runs as intended.
        //Certain methods weren't directly called, but were instead called through the print method.
        
        Rect r1 = new Rect(1, 3, 5, 9);
        Rect r2 = new Rect(4, 5, 9, 9);
        
        r1.print();
        r2.print();
        
        System.out.println(" ");
        System.out.println("Above is before values are changed, below is after:");
        System.out.println(" ");
        
        r1.move(16,32);
        r2.move(4,19);
        
        r1.changeSize(9);
        r2.changeSize(12);
        
        r1.print();
        r2.print();
        
        System.out.println("Rectangle #1 is bigger than Rectangle #2: " + r1.isBiggerThan(r2));
    }
}
