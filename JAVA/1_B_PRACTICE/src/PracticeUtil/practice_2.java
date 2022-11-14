package src.PracticeUtil;

import java.util.*;

public class practice_2 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);

        System.out.print("Enter your name : ");
        String name = sc.nextLine();
        System.out.print("What country do you want to visit? : ");
        String country = sc.nextLine();
        System.out.print("Enter your age : ");
        int age = sc.nextInt();
        System.out.print("Enter your final grade in SHS : ");
        double grade = sc.nextDouble();
        System.out.print("Do you like eating takoyaki? : ");
        boolean bn = sc.nextBoolean();

        sc.close();

        System.out.println("\n\nI am " + name);
        System.out.println("I am " + age + " yrs old");
        System.out.println("My final grade in SHS is " + grade);
        System.out.println("Do you like eating takoyaki? : " + bn);
        System.out.println("Someday I will travel to " + country);
    }
}
