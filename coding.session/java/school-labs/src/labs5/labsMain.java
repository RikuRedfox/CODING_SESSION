package src.labs5;

import java.util.Scanner;

public class labsMain {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int respond;
        while (true) {
            while (true) {
                System.out.println("\tEnter what type of encryption algorithm you want : ");
                System.out.print("(Type: '1' based on ASCII table | '2' based on Letters only) \n: ");
                respond = sc.nextInt();

                if (respond == 1) {
                    labsCipherASCII lCASCII = new labsCipherASCII();
                    break;
                }
                if (respond == 2) {
                    labsCipherLetters lCLetters = new labsCipherLetters();
                    break;
                }
            }
            System.out.println("You want to try again or try other?");
            System.out.print("(Type: '1' for yes | 'any' for no) : ");
            respond = sc.nextInt();
            if (respond == 1) {
                continue;
            }
            break;
        }
    }
}


