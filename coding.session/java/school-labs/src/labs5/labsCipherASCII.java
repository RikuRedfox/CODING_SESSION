package src.labs5;

import java.util.Scanner;

public class labsCipherASCII {
    static Scanner sc = new Scanner(System.in);

    static public String text = new String();
    static public int key;
    static public char[] chars;

    labsCipherASCII(){
        Encrypt();
        sc.nextLine();
        Decrypt();
    }

    public static void Encrypt() {
        System.out.print("\nEnter an text to Encrypt : ");
        text = sc.nextLine().toUpperCase();
        System.out.print("Enter shift key : ");
        key = sc.nextInt();

        chars = text.toCharArray();
        System.out.print("\nEncrypted text : ");

        // Encrypting method based on ASCII table
        for (char c : chars) {
            c += key;
            System.out.print(c);
        }
    }

    public static void Decrypt() {
        System.out.print("\nEnter an text to Decrypt : ");
        text = sc.nextLine().toUpperCase();
        System.out.print("Enter shift key : ");
        key = sc.nextInt();

        chars = text.toCharArray();
        System.out.print("\nDecrypted text : ");

        // Decrypting method based on ASCII table
        for (char c : chars) {
            c -= key;
            System.out.print(c);
        }
    }
}
