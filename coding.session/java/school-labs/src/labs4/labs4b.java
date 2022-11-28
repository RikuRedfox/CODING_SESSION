package src.labs4;

import java.util.Scanner;

public class labs4b {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        char dec;
        while (true) {
            try {
                System.out.println("\n   Todays Menu:\t\t Price");
                System.out.println("1. Adobo w/ Rice\tPhp 100");
                System.out.println("2. Menudo w/ Rice\tPhp 90");
                System.out.println("3. B-B-Q w/ Rice\tPhp 50");
                System.out.print("Your order? (1-3) : ");
                int ch = sc.nextInt();

                switch (ch) {
                    case 1:
                        while (true) {
                            System.out.println("\nAdobo with Rice");
                            System.out.println("Price : " + 100);
                            System.out.print("Enter Cash : ");
                            int c = sc.nextInt();
                            if (c < 100) {
                                System.out.println("Insufficient amount.");
                                continue;
                            }
                            int tl = (c - 100);
                            System.out.println("Change : " + tl);
                            break;
                        }
                        break;
                    case 2:
                        while (true) {
                            System.out.println("\nMenudo with Rice");
                            System.out.println("Price : " + 90);
                            System.out.print("Enter Cash : ");
                            int c = sc.nextInt();
                            if (c < 90) {
                                System.out.println("\nInsufficient amount.");
                                continue;
                            }
                            int tl = (c - 90);
                            System.out.println("\nChange:" + tl);
                            break;
                        }
                        break;
                    case 3:
                        while (true) {
                            System.out.println("B-B-Q with Rice");
                            System.out.println("Price : " + 50);
                            System.out.println("Enter Cash : ");
                            int c = sc.nextInt();
                            if (c < 50) {
                                System.out.println("\nInsufficient amount.");
                                continue;
                            }
                            int tl = (c - 50);
                            System.out.println("Change : " + tl);
                            break;
                        }
                        break;
                    default:
                        System.out.println("\nOut of order.\n");
                        break;
                }

            } catch (Exception e) {
                while (true) {
                    sc.next();
                    System.out.print("ERROR : Invalid input. Try again? (Y/N) : ");
                    dec = sc.next().charAt(0);

                    if (dec == 'Y' || dec == 'y') {
                        break;
                    } else if (dec == 'N' || dec == 'n') {
                        break;
                    }
                }

                if (dec == 'Y' || dec == 'y') {
                    continue;
                } else if (dec == 'N' || dec == 'n') {
                    System.out.println("\nHave a nice day!");
                    break;
                }
                sc.next();
            }
            while (true) {
                try {
                    System.out.print("\nNext Order? (Y/N) : ");
                    dec = sc.next().charAt(0);

                    if (dec == 'Y' || dec == 'y') {
                        break;
                    } else if (dec == 'N' || dec == 'n') {
                        break;
                    }
                } catch (Exception e) {
                    System.err.println("ERROR : input.");
                }
            }
            if (dec == 'Y' || dec == 'y') {
                continue;
            } else if (dec == 'N' || dec == 'n') {
                System.out.println("\nHave a nice day!");
                break;
            }
        }
        sc.close();
    }
}