package src.labs5;

import java.util.Scanner;
import java.util.regex.Pattern;

public class labsCipherLetters {
    static Scanner sc = new Scanner(System.in);

    public static final String letters = "ABCDEFGHIJKLNMOPQRSTUVWXYZ";

    labsCipherLetters() {
        String message = new String();
        int key = 0;
        while (true) {
            sc.nextLine();
            System.out.print("\nEnter the String for Encryption : ");
            message = sc.nextLine();
            if (Pattern.compile("[0-9]").matcher(message).find()) {
                continue;
            }
            break;
        }
        while (true) {
            try {
                System.out.print("Enter Shift Key : ");
                key = sc.nextInt();

            } catch (Exception e) {
                System.err.println("Something went wrong!");
                sc.nextLine();
                continue;
            }
            break;
        }
        System.out.println("\nEncrypt msg : " + encrypt(message, key));

        sc.nextLine();

        while (true) {
            System.out.print("\nEnter the String for Decryption : ");
            message = sc.nextLine();
            if (Pattern.compile("[0-9]").matcher(message).find()) {
                continue;
            }
            break;
        }
        while (true) {
            try {
                System.out.print("Enter Shift Key : ");
                key = sc.nextInt();
            } catch (Exception e) {
                System.err.println("Something went wrong!");
                sc.nextLine();
                continue;
            }
            break;
        }
        System.out.println("\nDecrypted msg : " + decrypt(message, key));

    }

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
}
