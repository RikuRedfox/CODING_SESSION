package src.PracticeSwing;
import java.util.Scanner;

//Input and Scanner.
public class practice_0 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        //User enter their nickname here.
        System.out.println("Enter your nickname: ");
        String nName = input.nextLine();

        //User enter their age here.
        System.out.println("Enter your age: ");
        String uAge = input.nextLine();
        int xAge = Integer.parseInt(uAge);
        input.close();

        //Output goes here.
        System.out.println("Your nickname is: " + nName);
        System.out.println("Your age is: "+ xAge);
    }
}