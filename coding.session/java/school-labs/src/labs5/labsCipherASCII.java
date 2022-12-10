package src.labs5;

import java.util.Scanner;

public class labsCipherASCII {
    static Scanner sc = new Scanner(System.in);

    static public String text = new String();
    static public int key;
    static public char[] chars;

    labsCipherASCII() {
        Encrypt();
        sc.nextLine();
        Decrypt();
        System.out.println();
    }

    public static void Encrypt() {
        System.out.print("\nEnter an text to Encrypt : ");
        text = sc.nextLine().toUpperCase();

        while (true) {
            try {
                System.out.print("Enter shift key : ");
                key = sc.nextInt();
                if(key > 0){
                    System.err.println("\nYou can't shift the key in less than 1.\n");
                    continue;
                }
            } catch (Exception e) {
                System.err.println("\nSomething went wrong!\n");
                sc.nextLine();
                continue;
            }
            break;
        }

        chars = text.toCharArray();
        System.out.print("\nEncrypted text : ");

        // Encrypting method based on ASCII table
        for (char c : chars) {
            c += key;
            System.out.print(c);
        }
    }

    public static void Decrypt() {
        System.out.print("\n\nEnter an text to Decrypt : ");
        text = sc.nextLine().toUpperCase();
        while (true) {
            try {
                System.out.print("Enter shift key : ");
                key = sc.nextInt();
            } catch (Exception e) {
                System.err.println("\nSomething went wrong!\n");
                sc.nextLine();
                if(key > 0){
                    System.err.println("\nYou can't shift the key in less than 1.\n");
                    continue;
                }
                continue;
            }
            break;
        }

        chars = text.toCharArray();
        System.out.print("\nDecrypted text : ");

        // Decrypting method based on ASCII table
        for (char c : chars) {
            c -= key;
            System.out.print(c);
        }
    }
}
