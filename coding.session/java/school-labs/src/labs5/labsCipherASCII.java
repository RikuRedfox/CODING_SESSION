package src.labs5;

import java.util.Scanner;

public class labsCipherASCII {
    static Scanner sc = new Scanner(System.in);

    static public String text = new String();
    static public int key;
    static public char[] chars;

    public void CipherASCII() {
        System.out.println("\tCipher ASCII\n");
        {
            System.out.print("Enter an text to Encrypt : ");
            text = sc.nextLine().toUpperCase();

            while (true) {
                try {
                    System.out.print("Enter shift key : ");
                    key = sc.nextInt();
                    if (key < 1) {
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
        sc.nextLine();
        {
            System.out.print("\n\nEnter an text to Decrypt : ");
            text = sc.nextLine().toUpperCase();
            while (true) {
                try {
                    System.out.print("Enter shift key : ");
                    key = sc.nextInt();
                } catch (Exception e) {
                    System.err.println("\nSomething went wrong!\n");
                    sc.nextLine();
                    if (key < 0) {
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

        System.out.println();
    }
}
