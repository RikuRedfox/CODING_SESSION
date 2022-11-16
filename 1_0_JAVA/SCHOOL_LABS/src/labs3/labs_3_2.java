package src.labs3;
// Andrew Jules R. Miyajima | 11/2/2022;
// reversing input number
import java.util.*;

public class labs_3_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, t, r = 0;
        System.out.print("Enter any number : ");
        n = sc.nextInt();
        System.out.println("The original number : " + n + "\n");
        sc.close();

        do {
            t = n % 10; 
		    // Getting the last number as a remainder.
            // Ex.: If you input 12345, the result is 1234.5; the .5 is the reminder.
            r = r * 10 + t; 
		    // It is like an indicator for the current reversed number. 
		    // r = 0, then multiplied by 10, that is 0, but if you add the t, ex., 5, that will be the value of the r, and that will repeat on the loop.
            n = n / 10; 
		    // To continue the loop, divide n by 10.
            // Will repeat until n is equal to 0.

            System.out.println("t = n % 10 = " + t + " | n = n / 10 = " + n + " | r = r * 10 + t = " + r);
        } while (n > 0);
        System.out.println("\nThe reverse of the number is : " + r); // Print the final result or reverse number.
    }
}
