package src.labs5;

import java.util.Scanner;

public class labsMain {

    public static labsCipherASCII cAscii = new labsCipherASCII();
    public static labsCipherLetters cLetter = new labsCipherLetters();

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        char respond;
        while (true) {
            System.out.print("\033[H\033[2J");
            System.out.flush();
            while (true) {
                System.out.println("\n\tEnter what type of encryption algorithm you want : ");
                System.out.print("(Type: 'A' based on ASCII table | 'B' based on Letters only | 'any' to exit.) \n: ");
                respond = sc.next().toUpperCase().charAt(0);

                if (respond == 'A' || respond == 'B') {
                    sc.nextLine();
                    System.out.print("\033[H\033[2J");
                    System.out.flush();
                    if (respond == 'A') {
                        cAscii.CipherASCII();
                    }
                    if (respond == 'B') {
                        cLetter.CipherLetters();
                    }
                }
                break;
            }
            if (!(respond == 'A' || respond == 'B')) {
                break;
            }
            System.out.println("\n\tYou want to try again or try other?");
            System.out.print("(Type: 'Y' for yes | 'any' for no) : ");
            respond = sc.next().toUpperCase().charAt(0);
            if (respond != 'Y') {
                break;
            }
        }
    }
}
