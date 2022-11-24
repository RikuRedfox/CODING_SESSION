package src.labs4;

import java.util.Scanner;

public class labs4 {
  public static void main(String[] args) {
    String summaryOrder[][] = new String[99][99]; // Here will store the orders
    while (true) {
      int i = 0;
      // Order
      while (true) {
        Scanner sc = new Scanner(System.in);
        while (true) { // Will repeat the order if the user want to order again
                       // or the input are not in the list
          sc.nextLine();
          int order, qty;
          System.out.println("\tMenu");
          System.out.println("[1] Adobo w/ rice\tPhp 100.00");
          System.out.println("[2] Menudo /w rice\tPhp 90.00");
          System.out.println("[3] Hotdog w/ rice\tPhp 50.00");

          try {
            System.out.print("Order: ");
            order = sc.nextInt();
            System.out.print("Quantity: ");
            qty = sc.nextInt();

            switch (order) {
              case 1:
                summaryOrder[i][0] = "Adobo w/ rice";
                summaryOrder[i][1] = "100";
                summaryOrder[i][2] = Integer.toString(qty);
                break;
              case 2:
                summaryOrder[i][0] = "Menudo w/ rice";
                summaryOrder[i][1] = "90";
                summaryOrder[i][2] = Integer.toString(qty);
                break;
              case 3:
                summaryOrder[i][0] = "Hotdog w/ rice";
                summaryOrder[i][1] = "50";
                summaryOrder[i][2] = Integer.toString(qty);
                break;
            }
            if (order > 3 || order < 1) {
              continue;
            } else if (order == 1 || order == 2 || order == 3) {
              break;
            }
          } catch (Exception e) {
            System.err.println("\nERROR: Don't put a letter(s), try again.");
          }
        }

        for (int j = 0; j <= i; j++) {
          System.out.println("Item " + j + " : " + summaryOrder[j][0] +
              " | Quantity : " + summaryOrder[j][2] +
              " | Unit price : " + summaryOrder[j][1] +
              " Amount Sale : " +
              (Integer.parseInt(summaryOrder[j][1]) *
                  Integer.parseInt(summaryOrder[j][2])));
        }

        System.out.print("\nAnything else? [1] Yes | [any] No : ");
        char dec = sc.next().charAt(0);
        sc.nextLine();

        if (dec != '1') {
          break;
        }
        i++;
      }
      // In this section the program will review the orders that user requested and give the total amount to paid
      Scanner in = new Scanner(System.in);

      System.out.println("\nOrder Summary : \n");
      int total = 0, cash, amount;

      for (int j = 0; j <= i; j++) {
        amount = (Integer.parseInt(summaryOrder[j][1]) *
            Integer.parseInt(summaryOrder[j][2]));
        total += amount;
        System.out.println("Item " + j + " : " + summaryOrder[j][0] +
            " | Quantity : " + summaryOrder[j][2] +
            " | Unit Price : " + summaryOrder[j][1] +
            " | Amount of sale : " +
            (Integer.parseInt(summaryOrder[j][1]) *
                Integer.parseInt(summaryOrder[j][2])));
      }

      System.out.println("\nTotal : " + total);
      while (true) {
        System.out.print("Enter Cash : ");
        cash = in.nextInt();

        if (cash >= total) {
          break;
        }
        System.out.println("Insufficient funds.");
      }

      System.out.println("Change : " + (cash - total));

      System.out.print(
          "Do you want to make another transaction? [1] Yes | [any] No : ");
      char dec = in.next().charAt(0);
      in.nextLine();

      if (dec != '1') {
        break;
      }
    }
    System.out.println("Okay have a nice day!");
  }
}