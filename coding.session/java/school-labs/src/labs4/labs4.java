package src.labs4;

import java.util.*;

public class labs4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try{
            while(true){
                String[][] summaryOrders = {{"", "", ""}, {"", "", ""},{"", "", ""}};
                int i = 0;
                while(true){
                    int order, qty; // price, total;
                    
                    System.out.println("\tMenu");
                    System.out.println("1.) Adobo w/ Rice\t Php 100");
                    System.out.println("2.) Menudo w/ Rice\t Php 90");
                    System.out.println("3.) Hotdog w/ Rice\t Php 50");
    
                        System.out.print("Order: ");
                        order = sc.nextInt();
                        System.out.print("Quantity: ");
                        qty = sc.nextInt();
                        if(order > 3 || order < 1){
                            throw new Exception("Error: Not in Menu.");
                        } else{
                            break;
                        }
                    
                    switch(order){
                        case 1:
                            summaryOrders[i][0] = "Adobo w/ Rice";
                            summaryOrders[i][1] = "100";
                            summaryOrders[i][2] = Integer.toString(qty);
                            break;
                        case 2:
                            summaryOrders[i][0] = "Menudo w/ Rice";
                            summaryOrders[i][1] = "90";
                            summaryOrders[i][2] = Integer.toString(qty);
                            break;
                        case 3:
                            summaryOrders[i][0] = "Hotdog w/ Rice";
                            summaryOrders[i][1] = "50";
                            summaryOrders[i][2] = Integer.toString(qty);
                            break;
                        default:
                            System.out.println("Not in Menu!");
                            break;
                    
                    for(int x = 0; x <= i; x++) {
                        System.out.println("Item " + x + " : " + summaryOrders[x][0] + " | Quantity : " + summaryOrders[x][2] + " | Unit price :" + summaryOrders[x][1] + " | Amount of Sale : " + Integer.parseInt(summaryOrders[x][1]) * Integer.parseInt(summaryOrders[x][2]) );
                    
                    }
                    System.out.print("\nDo you want to order again? [1]Yes [any] No : ");
                    int dec;
                    dec = sc.nextInt();
    
                    if(dec != 1){
                        break;
                    }
                    i++;
                }
                System.out.println("Order Summary: ");
                int total = 0, cash, amount;
    
                for(int x = 0; x <= i; x++ ){
                    amount = Integer.parseInt(summaryOrders[x][1]) * Integer.parseInt(summaryOrders[x][2]);
                    total += amount;
                    System.out.println("Item " + x + " : " + summaryOrders[x][0] + " | Quantity " + summaryOrders[x][2] + "| Unit Price : " + summaryOrders[x][1] + "| Amount of Sale : " + (Integer.parseInt(summaryOrders[x][1]) * Integer.parseInt(summaryOrders[x][2])) );
                }
    
                System.out.println("Total : " + total);
                while(true){
                    System.out.print("Enter Cash : ");
                    cash = sc.nextInt();
    
                    if(cash >= total){
                        break;
                    }
                    System.out.println("Unsufficient funds.");
                }
                System.out.println("Change : " + (cash - total));
    
                int dec;
                System.out.print("Do you want to make another transaction? [1] Yes | [any] No:");
                dec = sc.nextInt();
                if(dec != 1){
                    break;
                }
            }
            System.out.println("Okay have a nice day!");
            sc.close();
        }
        } catch(Exception Error){
            System.out.println(Error);
        }
    }
}
