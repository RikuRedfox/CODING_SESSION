package src.labs5;

import java.util.*;
// import java.io.*;

public class labs5 {
    static Scanner sc = new Scanner(System.in);

    public class Cipher {
        public static final String letters = "ABCDEFGHIJKLNMOPQRSTUVWXYZ";
        // public static final int numberLetters[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };

        public static String encrypt(String message, int shiftKey) {
            message = message.toUpperCase();
            String cipherText = "";

            for (int i = 0; i < message.length(); i++) {
                int charPosiion = letters.indexOf(message.charAt(i));
                int keyVal = (shiftKey + charPosiion) % 26;
                char replaceVal = letters.charAt(keyVal);
                cipherText += replaceVal;
            }
            return cipherText;
        }

        public static String decrypt(String cipherText, int shiftKey) {
            cipherText = cipherText.toUpperCase();
            String messaage = "";
            for (int i = 0; i < cipherText.length(); i++) {
                int charPosiion = letters.indexOf(cipherText.charAt(i));
                int keyVal = (charPosiion - shiftKey) % 26;
                if (keyVal < 0) {
                    keyVal = letters.length() + keyVal;
                }
                char replaceVal = letters.charAt(keyVal);
                messaage += replaceVal;
            }
            return messaage;
        }

        public static void main(String[] args) {
            String message = new String();
            int key = 0;
            {
                System.out.print("Enter the String for Encrpttion : ");
                message = sc.nextLine();

                System.out.print("\n\nEnter Shift Key : ");
                key = sc.nextInt();

                System.out.println("\nEncrypt msg : " + encrypt(message, key));
            }
            sc.nextLine();
            message = "";
            key = 0;
            {
                System.out.print("Enter the String for Encrpttion : ");
                message = sc.nextLine();
                System.out.print("\n\nEnter Shift Key : ");
                key = sc.nextInt();

                System.out.println("\nDecrypted msg : " + decrypt(message, key));

            }
        }
    }
}
