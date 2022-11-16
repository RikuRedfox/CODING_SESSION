package src.labs3;
// try catch 
public class labs_3_1 {
    public static void main(String[] args) {
        int d, a;
        try{
            d = 0;
            a = 42 / d;
            a = a / d;
            System.out.println("This will be printed if d is greater than zero.");
        } catch(ArithmeticException e){
            // catch divide-by-zero
            System.out.println("a has been divided by zero.");
        } 
        System.out.println("After catch statement.");
    }
}