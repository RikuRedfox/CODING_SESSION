package src.labs5;

import java.util.*;

public class labs5Basic {

    static Scanner sc = new Scanner(System.in);

    static public String text = new String();
    static public int key;
    static public char[] chars;

    public static void main(String[] args) {
        Encrypt();

        sc.nextLine();

        Decrypt();
    }

    public static void Encrypt() {
        System.out.print("\n\nEnter an text to Encrypt : ");
        text = sc.nextLine();
        text.toUpperCase();
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
        System.out.print("\n\nEnter an text to Decrypt : ");
        text = sc.nextLine();
        text.toUpperCase();
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
