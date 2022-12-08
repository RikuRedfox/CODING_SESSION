package src.labs5;

import java.util.Scanner;

public class labsMain {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String respond;
        while (true) {
            while (true) {
                System.out.println("\tEnter what type of encryption algorithm you want : ");
                System.out.print("(Type: 'ASCII' based on ASCII table or 'Letter' based on Letters only) \n: ");
                respond = sc.nextLine().toLowerCase();

                if (respond == "ascii") {
                    labsCipherASCII lCASCII = new labsCipherASCII();
                    break;
                }
                if (!(respond == "letter")) {
                    labsCipherLetters lCLetters = new labsCipherLetters();
                    break;
                }
            }
            System.out.println("You want to try again or try other?");
            System.out.print("(Type: 'Y' for yes | 'any' for no) : ");
            respond = sc.nextLine().toUpperCase();
            if (respond == "Y") {
                continue;
            }
            // break;
        }

    }
}
